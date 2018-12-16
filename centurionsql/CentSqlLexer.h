
// Generated from C:/Users/vasko/source/repos/presto/presto-parser/src/main/antlr4/com/facebook/presto/sql/parser\CentSql.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace centurion {


class  CentSqlLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, ADD = 10, ALL = 11, ALTER = 12, ANALYZE = 13, AND = 14, 
    ANY = 15, ARRAY = 16, AS = 17, ASC = 18, AT = 19, BERNOULLI = 20, BETWEEN = 21, 
    BY = 22, CALL = 23, CASCADE = 24, CASE = 25, CAST = 26, CATALOGS = 27, 
    COLUMN = 28, COLUMNS = 29, COMMENT = 30, COMMIT = 31, COMMITTED = 32, 
    CONSTRAINT = 33, CREATE = 34, CROSS = 35, CUBE = 36, CURRENT = 37, CURRENT_DATE = 38, 
    CURRENT_PATH = 39, CURRENT_TIME = 40, CURRENT_TIMESTAMP = 41, CURRENT_USER = 42, 
    DATA = 43, DATE = 44, DAY = 45, DEALLOCATE = 46, DELETE = 47, DESC = 48, 
    DESCRIBE = 49, DISTINCT = 50, DISTRIBUTED = 51, DROP = 52, ELSE = 53, 
    END = 54, ESCAPE = 55, EXCEPT = 56, EXCLUDING = 57, EXECUTE = 58, EXISTS = 59, 
    EXPLAIN = 60, EXTRACT = 61, FALSE_VALUE = 62, FILTER = 63, FIRST = 64, 
    FOLLOWING = 65, FOR = 66, FORMAT = 67, FROM = 68, FULL = 69, FUNCTIONS = 70, 
    GRANT = 71, GRANTS = 72, GRAPHVIZ = 73, GROUP = 74, GROUPING = 75, HAVING = 76, 
    HOUR = 77, IF = 78, IN = 79, INCLUDING = 80, INNER = 81, INPUT = 82, 
    INSERT = 83, INTERSECT = 84, INTERVAL = 85, INTO = 86, IO = 87, IS = 88, 
    ISOLATION = 89, JSON = 90, JOIN = 91, LAST = 92, LATERAL = 93, LEFT = 94, 
    LEVEL = 95, LIKE = 96, LIMIT = 97, LOCALTIME = 98, LOCALTIMESTAMP = 99, 
    LOGICAL = 100, MAP = 101, MINUTE = 102, MONTH = 103, NATURAL = 104, 
    NFC = 105, NFD = 106, NFKC = 107, NFKD = 108, NO = 109, NORMALIZE = 110, 
    NOT = 111, NULL_VALUE = 112, NULLIF = 113, NULLS = 114, ON = 115, ONLY = 116, 
    OPTION = 117, OR = 118, ORDER = 119, ORDINALITY = 120, OUTER = 121, 
    OUTPUT = 122, OVER = 123, PARTITION = 124, PARTITIONS = 125, PATH = 126, 
    POSITION = 127, PRECEDING = 128, PREPARE = 129, PRIVILEGES = 130, PROPERTIES = 131, 
    PUBLIC = 132, RANGE = 133, READ = 134, RECURSIVE = 135, RENAME = 136, 
    REPEATABLE = 137, REPLACE = 138, RESET = 139, RESTRICT = 140, REVOKE = 141, 
    RIGHT = 142, ROLLBACK = 143, ROLLUP = 144, ROW = 145, ROWS = 146, SCHEMA = 147, 
    SCHEMAS = 148, SECOND = 149, SELECT = 150, SERIALIZABLE = 151, SESSION = 152, 
    SET = 153, SETS = 154, SHOW = 155, SOME = 156, START = 157, STATS = 158, 
    SUBSTRING = 159, SYSTEM = 160, TABLE = 161, TABLES = 162, TABLESAMPLE = 163, 
    TEXT = 164, THEN = 165, TIME = 166, TIMESTAMP = 167, TO = 168, TRANSACTION = 169, 
    TRUE_VALUE = 170, TRY_CAST = 171, TYPE = 172, UESCAPE = 173, UNBOUNDED = 174, 
    UNCOMMITTED = 175, UNION = 176, UNNEST = 177, USE = 178, USING = 179, 
    VALIDATE = 180, VALUES = 181, VERBOSE = 182, VIEW = 183, WHEN = 184, 
    WHERE = 185, WITH = 186, WORK = 187, WRITE = 188, YEAR = 189, ZONE = 190, 
    EQ = 191, NEQ = 192, LT = 193, LTE = 194, GT = 195, GTE = 196, PLUS = 197, 
    MINUS = 198, ASTERISK = 199, SLASH = 200, PERCENT = 201, CONCAT = 202, 
    STRING = 203, UNICODE_STRING = 204, BINARY_LITERAL = 205, INTEGER_VALUE = 206, 
    DECIMAL_VALUE = 207, DOUBLE_VALUE = 208, IDENTIFIER = 209, DIGIT_IDENTIFIER = 210, 
    QUOTED_IDENTIFIER = 211, BACKQUOTED_IDENTIFIER = 212, TIME_WITH_TIME_ZONE = 213, 
    TIMESTAMP_WITH_TIME_ZONE = 214, DOUBLE_PRECISION = 215, SIMPLE_COMMENT = 216, 
    BRACKETED_COMMENT = 217, WS = 218, UNRECOGNIZED = 219
  };

  CentSqlLexer(antlr4::CharStream *input);
  ~CentSqlLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace centurion
