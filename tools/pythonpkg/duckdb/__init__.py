_exported_symbols = []

# Modules
import duckdb.functional as functional
import duckdb.typing as typing
_exported_symbols.extend([
    "typing",
    "functional"
])

# Classes
from .duckdb import (
    DuckDBPyRelation,
    DuckDBPyConnection,
    ExplainType,
    PythonExceptionHandling,
    RenderMode,
    Expression,
    ConstantExpression,
    ColumnExpression,
    StarExpression,
    FunctionExpression,
    CaseExpression,
)
_exported_symbols.extend([
    "DuckDBPyRelation",
    "DuckDBPyConnection",
    "ExplainType",
    "PythonExceptionHandling",
    "Expression",
    "ConstantExpression",
    "ColumnExpression",
    "StarExpression",
    "FunctionExpression",
    "CaseExpression",
])

# Enums
from .duckdb import (
    ANALYZE,
    DEFAULT,
    RETURN_NULL,
    STANDARD,
	COLUMNS,
	ROWS
)
_exported_symbols.extend([
    "ANALYZE",
    "DEFAULT",
    "RETURN_NULL",
    "STANDARD"
])

# Type-creation methods
from .duckdb import (
    struct_type,
    list_type,
    array_type,
    decimal_type
)
_exported_symbols.extend([
    "struct_type",
    "list_type",
    "array_type",
    "decimal_type"
])

# read-only properties
from .duckdb import (
    __standard_vector_size__,
    __interactive__,
    __jupyter__,
    __version__,
    apilevel,
    comment,
    default_connection,
    identifier,
    keyword,
    numeric_const,
    operator,
    paramstyle,
    string_const,
    threadsafety,
    token_type,
    tokenize
)
_exported_symbols.extend([
    "__standard_vector_size__",
    "__interactive__",
    "__jupyter__",
    "__version__",
    "apilevel",
    "comment",
    "default_connection",
    "identifier",
    "keyword",
    "numeric_const",
    "operator",
    "paramstyle",
    "string_const",
    "threadsafety",
    "token_type",
    "tokenize"
])

from .duckdb import (
    filter,
    project,
    aggregate,
    distinct,
    limit,
    query_df,
    order,
    alias,
    connect,
    write_csv
)
_exported_symbols.extend([
    "filter",
    "project",
    "aggregate",
    "distinct",
    "limit",
    "query_df",
    "order",
    "alias",
    "connect",
    "write_csv"
])

# TODO: might be worth seeing if these methods can be replaced with a pure-python solution
# Connection methods
from .duckdb import (
    append,
    array_type,
    arrow,
    begin,
    close,
    commit,
    create_function,
    cursor,
    decimal_type,
    description,
    df,
    dtype,
    duplicate,
    enum_type,
    execute,
    executemany,
    fetch_arrow_table,
    fetch_df,
    fetch_df_chunk,
    fetch_record_batch,
    fetchall,
    fetchdf,
    fetchmany,
    fetchnumpy,
    fetchone,
    filesystem_is_registered,
    from_arrow,
    from_csv_auto,
    from_df,
    from_parquet,
    from_query,
    from_substrait,
    from_substrait_json,
    get_substrait,
    get_substrait_json,
    get_table_names,
    install_extension,
    interrupt,
    list_filesystems,
    list_type,
    load_extension,
    map_type,
    pl,
    query,
    read_csv,
    read_json,
    read_parquet,
    register,
    register_filesystem,
    remove_function,
    rollback,
    row_type,
    rowcount,
    sql,
    sqltype,
    string_type,
    struct_type,
    table,
    table_function,
    tf,
    torch,
    type,
    union_type,
    unregister,
    unregister_filesystem,
    values,
    view
)
_exported_symbols.extend([
    "append",
    "array_type",
    "arrow",
    "begin",
    "close",
    "commit",
    "create_function",
    "cursor",
    "decimal_type",
    "description",
    "df",
    "dtype",
    "duplicate",
    "enum_type",
    "execute",
    "executemany",
    "fetch_arrow_table",
    "fetch_df",
    "fetch_df_chunk",
    "fetch_record_batch",
    "fetchall",
    "fetchdf",
    "fetchmany",
    "fetchnumpy",
    "fetchone",
    "filesystem_is_registered",
    "from_arrow",
    "from_csv_auto",
    "from_df",
    "from_parquet",
    "from_query",
    "from_substrait",
    "from_substrait_json",
    "get_substrait",
    "get_substrait_json",
    "get_table_names",
    "install_extension",
    "interrupt",
    "list_filesystems",
    "list_type",
    "load_extension",
    "map_type",
    "pl",
    "query",
    "read_csv",
    "read_json",
    "read_parquet",
    "register",
    "register_filesystem",
    "remove_function",
    "rollback",
    "row_type",
    "rowcount",
    "sql",
    "sqltype",
    "string_type",
    "struct_type",
    "table",
    "table_function",
    "tf",
    "torch",
    "type",
    "union_type",
    "unregister",
    "unregister_filesystem",
    "values",
    "view"
])

# Exceptions
from .duckdb import (
    Error,
    DataError,
    ConversionException,
    OutOfRangeException,
    TypeMismatchException,
    FatalException,
    IntegrityError,
    ConstraintException,
    InternalError,
    InternalException,
    InterruptException,
    NotSupportedError,
    NotImplementedException,
    OperationalError,
    ConnectionException,
    IOException,
    HTTPException,
    OutOfMemoryException,
    SerializationException,
    TransactionException,
    PermissionException,
    ProgrammingError,
    BinderException,
    CatalogException,
    InvalidInputException,
    InvalidTypeException,
    ParserException,
    SyntaxException,
    SequenceException,
    Warning
)
_exported_symbols.extend([
    "Error",
    "DataError",
    "ConversionException",
    "OutOfRangeException",
    "TypeMismatchException",
    "FatalException",
    "IntegrityError",
    "ConstraintException",
    "InternalError",
    "InternalException",
    "InterruptException",
    "NotSupportedError",
    "NotImplementedException",
    "OperationalError",
    "ConnectionException",
    "IOException",
    "HTTPException",
    "OutOfMemoryException",
    "SerializationException",
    "TransactionException",
    "PermissionException",
    "ProgrammingError",
    "BinderException",
    "CatalogException",
    "InvalidInputException",
    "InvalidTypeException",
    "ParserException",
    "SyntaxException",
    "SequenceException",
    "Warning"
])

# Value
from .value.constant import (
    Value,
    NullValue,
    BooleanValue,
    UnsignedBinaryValue,
    UnsignedShortValue,
    UnsignedIntegerValue,
    UnsignedLongValue,
    BinaryValue,
    ShortValue,
    IntegerValue,
    LongValue,
    HugeIntegerValue,
    FloatValue,
    DoubleValue,
    DecimalValue,
    StringValue,
    UUIDValue,
    BitValue,
    BlobValue,
    DateValue,
    IntervalValue,
    TimestampValue,
    TimestampSecondValue,
    TimestampMilisecondValue,
    TimestampNanosecondValue,
    TimestampTimeZoneValue,
    TimeValue,
    TimeTimeZoneValue,
)

_exported_symbols.extend([
    "Value",
    "NullValue",
    "BooleanValue",
    "UnsignedBinaryValue",
    "UnsignedShortValue",
    "UnsignedIntegerValue",
    "UnsignedLongValue",
    "BinaryValue",
    "ShortValue",
    "IntegerValue",
    "LongValue",
    "HugeIntegerValue",
    "FloatValue",
    "DoubleValue",
    "DecimalValue",
    "StringValue",
    "UUIDValue",
    "BitValue",
    "BlobValue",
    "DateValue",
    "IntervalValue",
    "TimestampValue",
    "TimestampSecondValue",
    "TimestampMilisecondValue",
    "TimestampNanosecondValue",
    "TimestampTimeZoneValue",
    "TimeValue",
    "TimeTimeZoneValue",
])

__all__ = _exported_symbols
