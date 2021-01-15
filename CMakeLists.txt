cmake_minimum_required(VERSION 3.13)
project(s19_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
add_executable(s19_printf
        src/formatter/pf_formatter_format_char.c
        src/formatter/pf_formatter_format_percent.c
        src/formatter/pf_formatter_format_str.c
        src/formatter/pf_formatter_main.c
        src/parser/pf_parser_main.c
        src/parser/pf_parser_parse_flags.c
        src/parser/pf_parser_parse_precision.c
        src/parser/pf_parser_parse_size.c
        src/parser/pf_parser_parse_width.c
        src/utils/pf_utils_pad.c
        src/utils/pf_utils_print_as_it.c
        src/utils/pf_utils_push_int.c
        src/ft_printf.c
        test.c)

find_library(LIBFT ft lib)
target_link_libraries(s19_printf LINK_PUBLIC ${LIBFT})