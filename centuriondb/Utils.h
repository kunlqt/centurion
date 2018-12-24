#pragma once
#include <cstdint>
#include <cstring>

using StringSizeType = std::uint32_t;

#define SetIndexId(buffer, indexId) *(IndexId*)buffer = indexId

#define GetIndexId(buffer) *(const IndexId*)buffer

#define SetStringSize(buffer, stringSize) *((StringSizeType*)((std::uint8_t*)buffer + sizeof(IndexId))) = stringSize

#define GetStringSize(buffer) *((StringSizeType*)((std::uint8_t*)buffer + sizeof(IndexId)))

#define StringBufferOffset (sizeof(IndexId) + sizeof(StringSizeType))

#define GetDocumentIdOffsetInString(stringSize) (StringBufferOffset + stringSize)

#define ExtractDocumentIdFromString(buffer) (*(DocumentId*)((std::uint8_t*)buffer + GetDocumentIdOffsetInString(GetStringSize(buffer))))

#define ExtractDocumentIdFromDouble(buffer) (*(DocumentId*)((std::uint8_t*)buffer + sizeof(IndexId) + sizeof(double)))

#define ExtractDocumentIdFromBoolean(buffer) (*(DocumentId*)((std::uint8_t*)buffer + sizeof(IndexId) + sizeof(std::uint8_t)))

#define SetStringData(dst, str, strSize) if (strSize > 0) memcpy(dst + StringBufferOffset, str, strSize)

#define CreateStringIndex(buffer, indexId, str, stringSize) \
	SetIndexId(buffer, indexId); \
	SetStringSize(buffer, stringSize); \
	if (stringSize && str) std::memcpy(((std::uint8_t*)buffer + StringBufferOffset), str, stringSize)

#define CreateDoubleIndex(buffer, indexId, v) \
	SetIndexId(buffer, indexId); \
	*(double*)((std::uint8_t*)buffer + sizeof(IndexId)) = v

#define CreateBooleanIndex(buffer, indexId, b) \
	SetIndexId(buffer, indexId); \
	*(std::uint8_t*)((std::uint8_t*)buffer + sizeof(IndexId)) = (b ? 1 : 0)

#define CreateEmptytringIndex(buffer, indexId)  \
	SetIndexId(buffer, indexId); \
	SetStringSize(buffer, 0);

#define CreateStringIndexSlice(indexId, str, stringSize, slice) \
	char slice##buffer[sizeof(IndexId) + sizeof(StringSizeType) + stringSize]; \
	CreateStringIndex(slice##buffer, indexId, str, stringSize); \
	slice = Slice(slice##buffer, sizeof(slice##buffer))

#define CreateDoubleIndexSlice(indexId, v, slice) \
	char slice##buffer[sizeof(IndexId) + sizeof(double)]; \
	CreateDoubleIndex(slice##buffer, indexId, v); \
	slice = Slice(slice##buffer, sizeof(slice##buffer))
