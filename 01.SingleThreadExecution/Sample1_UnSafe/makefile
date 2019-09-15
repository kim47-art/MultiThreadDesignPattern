PROG := myapp
SRCS := Main.cpp Gate.cpp UserThread.cpp
OBJS := $(SRCS:%.cpp=%.o)
DEPS := $(SRCS:%.cpp=%.d)

CC := g++

all: $(PROG)

-include $(DEPS)

$(PROG): $(OBJS)
	$(CC) -o $@ $^ -pthread

%.o: %.cpp
	$(CC) -c -MMD -MP $< 

clean:
	rm -f $(PROG) $(OBJS) $(DEPS)
