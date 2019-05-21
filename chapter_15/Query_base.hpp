#include "QueryResult.hpp"


class Query_base{
	friend class Query;
	public:
		using line_no = TextQuery::line_no;
		virtual ~Query_base() = default;
		virtual void setRange(size_t min,size_t max){
			minLineNum = min;
			maxLineNum = max;
		}
	private:
		virtual QueryResult eval(const TextQuery&) {}//const = 0;
		virtual string rep() const {}//= 0;
		size_t minLineNum;
		size_t maxLineNum;
};
