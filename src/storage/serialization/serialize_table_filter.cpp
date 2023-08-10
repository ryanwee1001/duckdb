//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/format_serializer.hpp"
#include "duckdb/common/serializer/format_deserializer.hpp"
#include "duckdb/planner/table_filter.hpp"
#include "duckdb/planner/filter/null_filter.hpp"
#include "duckdb/planner/filter/constant_filter.hpp"
#include "duckdb/planner/filter/conjunction_filter.hpp"

namespace duckdb {

void TableFilter::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "filter_type", filter_type);
}

unique_ptr<TableFilter> TableFilter::FormatDeserialize(FormatDeserializer &deserializer) {
	auto filter_type = deserializer.ReadProperty<TableFilterType>(/*100*/ "filter_type");
	unique_ptr<TableFilter> result;
	switch (filter_type) {
	case TableFilterType::CONJUNCTION_AND:
		result = ConjunctionAndFilter::FormatDeserialize(deserializer);
		break;
	case TableFilterType::CONJUNCTION_OR:
		result = ConjunctionOrFilter::FormatDeserialize(deserializer);
		break;
	case TableFilterType::CONSTANT_COMPARISON:
		result = ConstantFilter::FormatDeserialize(deserializer);
		break;
	case TableFilterType::IS_NOT_NULL:
		result = IsNotNullFilter::FormatDeserialize(deserializer);
		break;
	case TableFilterType::IS_NULL:
		result = IsNullFilter::FormatDeserialize(deserializer);
		break;
	default:
		throw SerializationException("Unsupported type for deserialization of TableFilter!");
	}
	return result;
}

void ConjunctionAndFilter::FormatSerialize(FormatSerializer &serializer) const {
	TableFilter::FormatSerialize(serializer);
	serializer.WriteProperty(200, "child_filters", child_filters);
}

unique_ptr<TableFilter> ConjunctionAndFilter::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ConjunctionAndFilter>(new ConjunctionAndFilter());
	deserializer.ReadProperty(/*200*/ "child_filters", result->child_filters);
	return std::move(result);
}

void ConjunctionOrFilter::FormatSerialize(FormatSerializer &serializer) const {
	TableFilter::FormatSerialize(serializer);
	serializer.WriteProperty(200, "child_filters", child_filters);
}

unique_ptr<TableFilter> ConjunctionOrFilter::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ConjunctionOrFilter>(new ConjunctionOrFilter());
	deserializer.ReadProperty(/*200*/ "child_filters", result->child_filters);
	return std::move(result);
}

void ConstantFilter::FormatSerialize(FormatSerializer &serializer) const {
	TableFilter::FormatSerialize(serializer);
	serializer.WriteProperty(200, "comparison_type", comparison_type);
	serializer.WriteProperty(201, "constant", constant);
}

unique_ptr<TableFilter> ConstantFilter::FormatDeserialize(FormatDeserializer &deserializer) {
	auto comparison_type = deserializer.ReadProperty<ExpressionType>(/*200*/ "comparison_type");
	auto constant = deserializer.ReadProperty<Value>(/*201*/ "constant");
	auto result = duckdb::unique_ptr<ConstantFilter>(new ConstantFilter(comparison_type, constant));
	return std::move(result);
}

void IsNotNullFilter::FormatSerialize(FormatSerializer &serializer) const {
	TableFilter::FormatSerialize(serializer);
}

unique_ptr<TableFilter> IsNotNullFilter::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<IsNotNullFilter>(new IsNotNullFilter());
	return std::move(result);
}

void IsNullFilter::FormatSerialize(FormatSerializer &serializer) const {
	TableFilter::FormatSerialize(serializer);
}

unique_ptr<TableFilter> IsNullFilter::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<IsNullFilter>(new IsNullFilter());
	return std::move(result);
}

} // namespace duckdb
