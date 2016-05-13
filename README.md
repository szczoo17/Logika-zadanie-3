#Part 1
compiling:  
  gcc -o part1 part1.c  
  gcc -o part1 part1neg.c  
example run:  
  ./part1 10 20 13 14 8 8  
check:  
  ./part1check.sh
  
#Part 2
compiling:  
  gcc -o part2 part2.c  
example run:  
  ./part2 --not not.txt --or or.txt --and and.txt --impl impl.txt  
