task: task.cpp Makefile
	g++ -std=c++17 -Wall -Wextra task.cpp -O2 -fopenmp -o $@

clean:
	@rm -f task
