main_rev.out: main_rev.cpp
	@$(CXX) -g -Wall $^ -o $@

main_rsum.out: main_rsum.cpp
	@$(CXX) -g -Wall $^ -o $@

rev: main_rev.out

rsum: main_rsum.out

format:
	@clang-format -i *.cpp *.h

clean:
	@rm *.out
