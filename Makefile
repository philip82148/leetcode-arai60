# 自分のVSCode用のCode Runnerという拡張機能用のMakefile
# Code Runner側でmake run src=$fullFileName debug=no opt=noを実行するようにしている

src = main.cpp
debug = yes
opt = yes

ESCAPED_SRC = $(shell echo $(src) | sed -e 's/ /\\ /g')

OPTIONS = -Wno-sign-compare -Wno-char-subscripts
DEFINES =
SRCS = $(ESCAPED_SRC)

ifneq ($(debug), no)
OPTIONS += -fdiagnostics-color=always -Wall -Wextra -Wfloat-equal -ftrapv -fstack-protector-all -fsanitize=address,undefined -fno-omit-frame-pointer -g
DEFINES += -D _GLIBCXX_DEBUG
endif
ifneq ($(opt), no)
OPTIONS += -O2
endif

run: $(SRCS)
	g++ -std=c++20 $(OPTIONS) $(DEFINES) $(SRCS) -o z.out && ./z.out
