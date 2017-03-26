## Test another file

Just testing another file and mentioning [](test_greeter_do_foo_bar) and [](TestGreeter)

This file is here to test "smart symbol lists generation", hotdoc should append symbols found in `test-other-file.c` and `test-other-file.h` here, because this file is named `test-other-file.markdown`, but it should preserve this text, and the header above. This behaviour is triggered by the usage of the `gi-smart-index` command-line argument.

Also including a C file:

{{ ../greeter_example.c }}
