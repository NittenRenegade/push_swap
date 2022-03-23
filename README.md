# push_swap
Project to produce a sorting algorithm with specific mechanism:
The stack a contains a random integers wich can not be duplicated. Stack b is empty.

Within the sorting process we should work the logic arround some operations determined by the subject. Bellow the list of operations:

- sa :swap 'a' - swap the first 2 elements at the top of stack 'a';
- sb :swap 'b' - swap the first 2 elements at the top of stack 'b';
- ss :sa and sb at the same time.
- pa :push 'a' - take the first element at the top of 'b' and put it at the top of 'a'.
- pb :push 'b' - take the first element at the top of 'a' and put it at the top of 'b'.
- ra :rotate 'a' - shift up all elements of stack 'a' by 1.
- rb :rotate 'b' - shift up all elements of stack 'b' by 1.
- rr :ra and rb at the same time.
- rra :reverse rotate 'a' - shift down all elements of stack 'a' by 1.
- rrb :reverse rotate 'b' - shift down all elements of stack 'b' by 1;
- rrr :rra and rrb at the same time.

Commands count limited ralate to size numbers stack.
- 3 elements must less than 3 commands
- 5 elemtnts must less than 12 commans
- 100 elements must less than 700 commands
- 500 elements must less than 5500 commands

My sorter respect all of these limits.

type 'make' to build project

to run visualizer:
setopt sh_wordsplit
python3 python_visualizer.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`

to console check:
ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`; ./push_swap $ARG | tee cmds; cat cmds | ./checker $ARG; cat cmds | wc -l
