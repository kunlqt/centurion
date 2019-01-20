#pragma once
#include <boost/algorithm/string.hpp>
#include <cstdint>
#include <cstring>

static double DefaultComparisionPrecision = 10e-8;

using StringSizeType = std::uint32_t;

#define SetIndexId(buffer, indexId) *(IndexId*)buffer = indexId

#define GetIndexId(buffer) *(const IndexId*)buffer

#define SetStringSize(buffer, stringSize) *((StringSizeType*)((std::uint8_t*)buffer + sizeof(IndexId))) = stringSize

#define GetStringSize(buffer) *((StringSizeType*)((std::uint8_t*)buffer + sizeof(IndexId)))

#define StringBufferOffset (sizeof(IndexId) + sizeof(StringSizeType))

#define GetDocumentIdOffsetInString(stringSize) (StringBufferOffset + stringSize)

#define ExtractDocumentIdFromString(buffer) (*(DocumentId*)((std::uint8_t*)buffer + GetDocumentIdOffsetInString(GetStringSize(buffer))))

#define ExtractDouble(buffer) (*(double*)((std::uint8_t*)buffer + sizeof(IndexId)))

#define ExtractDocumentIdFromDouble(buffer) (*(DocumentId*)((std::uint8_t*)buffer + sizeof(IndexId) + sizeof(double)))

#define ExtractDocumentIdFromBoolean(buffer) (*(DocumentId*)((std::uint8_t*)buffer + sizeof(IndexId) + sizeof(std::uint8_t)))

#define SetStringData(dst, str, strSize) if (strSize > 0) memcpy(dst + StringBufferOffset, str, strSize)

#define CreateStringIndex(buffer, indexId, str, stringSize) \
	SetIndexId(buffer, indexId); \
	SetStringSize(buffer, stringSize); \
	if (stringSize > 0) std::memcpy(((std::uint8_t*)buffer + StringBufferOffset), str, stringSize); \
	*(DocumentId*)((std::uint8_t*)buffer + StringBufferOffset + stringSize) = 0;

#define CreateDoubleIndex(buffer, indexId, v) \
	SetIndexId(buffer, indexId); \
	*(double*)((std::uint8_t*)buffer + sizeof(IndexId)) = v; \
	*(DocumentId*)((std::uint8_t*)buffer + sizeof(IndexId) + sizeof(double)) = 0;

#define CreateBooleanIndex(buffer, indexId, b) \
	SetIndexId(buffer, indexId); \
	*(std::uint8_t*)((std::uint8_t*)buffer + sizeof(IndexId)) = (b ? 1 : 0); \
	*(DocumentId*)((std::uint8_t*)buffer + sizeof(IndexId) + sizeof(std::uint8_t)) = 0;

#define CreateEmptyStringIndex(buffer, indexId)  \
	SetIndexId(buffer, indexId); \
	SetStringSize(buffer, 0);

#define CreateStringIndexSlice(indexId, str, stringSize, slice) \
	char slice##buffer[sizeof(IndexId) + sizeof(StringSizeType) + stringSize + sizeof(DocumentId)]; \
	CreateStringIndex(slice##buffer, indexId, str, stringSize); \
	slice = Slice(slice##buffer, sizeof(slice##buffer))

#define CreateDoubleIndexSlice(indexId, v, slice) \
	char slice##buffer[sizeof(IndexId) + sizeof(double) + sizeof(DocumentId)]; \
	CreateDoubleIndex(slice##buffer, indexId, v); \
	slice = Slice(slice##buffer, sizeof(slice##buffer))


static void MergeOverlappingFields(std::vector<std::string>& result) {
	if (result.size() > 1) {
		std::sort(result.begin(), result.end());
		for (auto it = result.begin(); it != result.end(); ++it)
		{
			const auto a = *it;
			auto it2 = it + 1;
			while (it2 != result.end()) {
				const auto b = *it2;
				if (boost::istarts_with(b, a)) {
					it2 = result.erase(it2);
				} else {
					break;
				}
			}
		}
	}
	if ((result.size() == 1) && (result.front() == "/")) {
		result.erase(result.begin());
	}
}
