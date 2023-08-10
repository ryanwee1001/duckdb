//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/format_serializer.hpp"
#include "duckdb/common/serializer/format_deserializer.hpp"
#include "duckdb/planner/expression/list.hpp"

namespace duckdb {

void Expression::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "expression_class", expression_class);
	serializer.WriteProperty(101, "type", type);
	serializer.WriteProperty(102, "alias", alias);
}

unique_ptr<Expression> Expression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto expression_class = deserializer.ReadProperty<ExpressionClass>(/*100*/ "expression_class");
	auto type = deserializer.ReadProperty<ExpressionType>(/*101*/ "type");
	auto alias = deserializer.ReadProperty<string>(/*102*/ "alias");
	deserializer.Set<ExpressionType>(type);
	unique_ptr<Expression> result;
	switch (expression_class) {
	case ExpressionClass::BOUND_AGGREGATE:
		result = BoundAggregateExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_BETWEEN:
		result = BoundBetweenExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_CASE:
		result = BoundCaseExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_CAST:
		result = BoundCastExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_COLUMN_REF:
		result = BoundColumnRefExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_COMPARISON:
		result = BoundComparisonExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_CONJUNCTION:
		result = BoundConjunctionExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_CONSTANT:
		result = BoundConstantExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_DEFAULT:
		result = BoundDefaultExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_FUNCTION:
		result = BoundFunctionExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_LAMBDA:
		result = BoundLambdaExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_LAMBDA_REF:
		result = BoundLambdaRefExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_OPERATOR:
		result = BoundOperatorExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_PARAMETER:
		result = BoundParameterExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_REF:
		result = BoundReferenceExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_UNNEST:
		result = BoundUnnestExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::BOUND_WINDOW:
		result = BoundWindowExpression::FormatDeserialize(deserializer);
		break;
	default:
		throw SerializationException("Unsupported type for deserialization of Expression!");
	}
	deserializer.Unset<ExpressionType>();
	result->alias = std::move(alias);
	return result;
}

void BoundBetweenExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "input", *input);
	serializer.WriteProperty(201, "lower", *lower);
	serializer.WriteProperty(202, "upper", *upper);
	serializer.WriteProperty(203, "lower_inclusive", lower_inclusive);
	serializer.WriteProperty(204, "upper_inclusive", upper_inclusive);
}

unique_ptr<Expression> BoundBetweenExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<BoundBetweenExpression>(new BoundBetweenExpression());
	deserializer.ReadProperty(/*200*/ "input", result->input);
	deserializer.ReadProperty(/*201*/ "lower", result->lower);
	deserializer.ReadProperty(/*202*/ "upper", result->upper);
	deserializer.ReadProperty(/*203*/ "lower_inclusive", result->lower_inclusive);
	deserializer.ReadProperty(/*204*/ "upper_inclusive", result->upper_inclusive);
	return std::move(result);
}

void BoundCaseExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
	serializer.WriteProperty(201, "case_checks", case_checks);
	serializer.WriteProperty(202, "else_expr", *else_expr);
}

unique_ptr<Expression> BoundCaseExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(/*200*/ "return_type");
	auto result = duckdb::unique_ptr<BoundCaseExpression>(new BoundCaseExpression(std::move(return_type)));
	deserializer.ReadProperty(/*201*/ "case_checks", result->case_checks);
	deserializer.ReadProperty(/*202*/ "else_expr", result->else_expr);
	return std::move(result);
}

void BoundCastExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "child", *child);
	serializer.WriteProperty(201, "return_type", return_type);
	serializer.WriteProperty(202, "try_cast", try_cast);
}

unique_ptr<Expression> BoundCastExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto child = deserializer.ReadProperty<unique_ptr<Expression>>(/*200*/ "child");
	auto return_type = deserializer.ReadProperty<LogicalType>(/*201*/ "return_type");
	auto result = duckdb::unique_ptr<BoundCastExpression>(new BoundCastExpression(deserializer.Get<ClientContext &>(), std::move(child), std::move(return_type)));
	deserializer.ReadProperty(/*202*/ "try_cast", result->try_cast);
	return std::move(result);
}

void BoundColumnRefExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
	serializer.WriteProperty(201, "binding", binding);
	serializer.WriteProperty(202, "depth", depth);
}

unique_ptr<Expression> BoundColumnRefExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(/*200*/ "return_type");
	auto binding = deserializer.ReadProperty<ColumnBinding>(/*201*/ "binding");
	auto depth = deserializer.ReadProperty<idx_t>(/*202*/ "depth");
	auto result = duckdb::unique_ptr<BoundColumnRefExpression>(new BoundColumnRefExpression(std::move(return_type), binding, depth));
	return std::move(result);
}

void BoundComparisonExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "left", *left);
	serializer.WriteProperty(201, "right", *right);
}

unique_ptr<Expression> BoundComparisonExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto left = deserializer.ReadProperty<unique_ptr<Expression>>(/*200*/ "left");
	auto right = deserializer.ReadProperty<unique_ptr<Expression>>(/*201*/ "right");
	auto result = duckdb::unique_ptr<BoundComparisonExpression>(new BoundComparisonExpression(deserializer.Get<ExpressionType>(), std::move(left), std::move(right)));
	return std::move(result);
}

void BoundConjunctionExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "children", children);
}

unique_ptr<Expression> BoundConjunctionExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<BoundConjunctionExpression>(new BoundConjunctionExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty(/*200*/ "children", result->children);
	return std::move(result);
}

void BoundConstantExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "value", value);
}

unique_ptr<Expression> BoundConstantExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto value = deserializer.ReadProperty<Value>(/*200*/ "value");
	auto result = duckdb::unique_ptr<BoundConstantExpression>(new BoundConstantExpression(value));
	return std::move(result);
}

void BoundDefaultExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
}

unique_ptr<Expression> BoundDefaultExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(/*200*/ "return_type");
	auto result = duckdb::unique_ptr<BoundDefaultExpression>(new BoundDefaultExpression(std::move(return_type)));
	return std::move(result);
}

void BoundLambdaExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
	serializer.WriteProperty(201, "lambda_expr", *lambda_expr);
	serializer.WriteProperty(202, "captures", captures);
	serializer.WriteProperty(203, "parameter_count", parameter_count);
}

unique_ptr<Expression> BoundLambdaExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(/*200*/ "return_type");
	auto lambda_expr = deserializer.ReadProperty<unique_ptr<Expression>>(/*201*/ "lambda_expr");
	auto captures = deserializer.ReadProperty<vector<unique_ptr<Expression>>>(/*202*/ "captures");
	auto parameter_count = deserializer.ReadProperty<idx_t>(/*203*/ "parameter_count");
	auto result = duckdb::unique_ptr<BoundLambdaExpression>(new BoundLambdaExpression(deserializer.Get<ExpressionType>(), std::move(return_type), std::move(lambda_expr), parameter_count));
	result->captures = std::move(captures);
	return std::move(result);
}

void BoundLambdaRefExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
	serializer.WriteProperty(201, "binding", binding);
	serializer.WriteProperty(202, "lambda_index", lambda_index);
	serializer.WriteProperty(203, "depth", depth);
}

unique_ptr<Expression> BoundLambdaRefExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(/*200*/ "return_type");
	auto binding = deserializer.ReadProperty<ColumnBinding>(/*201*/ "binding");
	auto lambda_index = deserializer.ReadProperty<idx_t>(/*202*/ "lambda_index");
	auto depth = deserializer.ReadProperty<idx_t>(/*203*/ "depth");
	auto result = duckdb::unique_ptr<BoundLambdaRefExpression>(new BoundLambdaRefExpression(std::move(return_type), binding, lambda_index, depth));
	return std::move(result);
}

void BoundOperatorExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
	serializer.WriteProperty(201, "children", children);
}

unique_ptr<Expression> BoundOperatorExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(/*200*/ "return_type");
	auto result = duckdb::unique_ptr<BoundOperatorExpression>(new BoundOperatorExpression(deserializer.Get<ExpressionType>(), std::move(return_type)));
	deserializer.ReadProperty(/*201*/ "children", result->children);
	return std::move(result);
}

void BoundParameterExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "identifier", identifier);
	serializer.WriteProperty(201, "return_type", return_type);
	serializer.WriteProperty(202, "parameter_data", *parameter_data);
}

unique_ptr<Expression> BoundParameterExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto identifier = deserializer.ReadProperty<string>(/*200*/ "identifier");
	auto return_type = deserializer.ReadProperty<LogicalType>(/*201*/ "return_type");
	auto parameter_data = deserializer.ReadProperty<shared_ptr<BoundParameterData>>(/*202*/ "parameter_data");
	auto result = duckdb::unique_ptr<BoundParameterExpression>(new BoundParameterExpression(deserializer.Get<bound_parameter_map_t &>(), std::move(identifier), std::move(return_type), std::move(parameter_data)));
	return std::move(result);
}

void BoundReferenceExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
	serializer.WriteProperty(201, "index", index);
}

unique_ptr<Expression> BoundReferenceExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(/*200*/ "return_type");
	auto index = deserializer.ReadProperty<idx_t>(/*201*/ "index");
	auto result = duckdb::unique_ptr<BoundReferenceExpression>(new BoundReferenceExpression(std::move(return_type), index));
	return std::move(result);
}

void BoundUnnestExpression::FormatSerialize(FormatSerializer &serializer) const {
	Expression::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
	serializer.WriteProperty(201, "child", *child);
}

unique_ptr<Expression> BoundUnnestExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(/*200*/ "return_type");
	auto result = duckdb::unique_ptr<BoundUnnestExpression>(new BoundUnnestExpression(std::move(return_type)));
	deserializer.ReadProperty(/*201*/ "child", result->child);
	return std::move(result);
}

} // namespace duckdb
