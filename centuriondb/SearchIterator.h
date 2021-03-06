#pragma once

#include "DocumentId.h"
#include "IndexId.h"
#include <rocksdb/iterator.h>
#include <rocksdb/options.h>
#include <functional>

namespace centurion
{
	//struct SearchIterator : public std::iterator<std::forward_iterator_tag, DocumentId>
	enum StateFlags
	{
		None = 0,
		BeforeFirst = 1,
		First = 2,
		AfterLast = 8
	};

	inline StateFlags operator | (StateFlags lhs, StateFlags rhs)
	{
		using T = std::underlying_type_t <StateFlags>;
		return static_cast<StateFlags>(static_cast<T>(lhs) | static_cast<T>(rhs));
	}

	inline StateFlags& operator |= (StateFlags& lhs, StateFlags rhs)
	{
		lhs = lhs | rhs;
		return lhs;
	}
	enum FieldType { kDouble, kBoolean, kString, kStringArray };
	
	struct SearchIterator
	{		
		SearchIterator() : stateFlags_(BeforeFirst) {}
		virtual ~SearchIterator() {};
		virtual DocumentId current() const = 0;
		virtual void seek(
			std::function<IndexId(FieldType, const std::string&)> fieldNameResolver,
			std::function<rocksdb::Iterator*(FieldType, const rocksdb::Slice*, const rocksdb::Slice*)> iteratorBuilder,
			DocumentId documentId) = 0;
		virtual void next() = 0;

		virtual bool valid() const 
		{
			return stateFlags_ == None || stateFlags_ == First;
		}

		void setState(StateFlags flags)
		{
			stateFlags_ = flags;
		}

		StateFlags getState() const { return  stateFlags_; }

	private:
		StateFlags stateFlags_;
	};

}
