local ffi = require("ffi")

ffi.cdef [[
typedef struct options {
	const char *to_parse;
	const char *name_space;
	bool typedefs_in_header;
	const char *includes_in_file;
	const char *json_parser_file;
	const char *dirname;
	const char *fname;
	const char *vector_lib;
	const char *vector_name;
	const char *string_lib;
	const char *string_name;
} options;
void parse_pocket_format(options *opt);
]]

local dll = ffi.load("pocket-format-dll")

function parse(options)
    opt = ffi.new("options")
    opt.to_parse = options.to_parse
    opt.name_space = options.name_space or "pocket"
    opt.typedefs_in_header = options.typedefs_in_header or false
    opt.includes_in_file = options.includes_in_file or "<pocket/core/types.hpp>"
	opt.json_parser_file = options.json_parser_file or "<pocket/json/json.hpp>"
	opt.dirname = options.dirname or "./"
	opt.fname = options.fname or "output"
	opt.vector_lib = options.vector_lib or "<pocket/containers/vector.hpp>"
	opt.vector_name = options.vector_name or "mem::vector"
	opt.string_lib = options.string_lib or "<pocket/containers/string.hpp>"
	opt.string_name = options.string_name or "mem::string"

    dll.parse_pocket_format(opt)
end

parse({
    to_parse = "tileset.data",
    dirname = "../src/pocket/generated/",
    fname = "tileset_data",
	includes_in_file = "#include <pocket/core/types.hpp>\n#include <pocket/containers/containers.hpp>"
})

return {
    parse = parse
}
