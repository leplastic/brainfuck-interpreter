++++++++++          | Cell 0 is 10
[                   | Repeats till cell 0 is 0
    >+              | Cell 1 is 1  (will be ASCII 10  = __LF__)
	    >+++            | Cell 2 is 3  (will be ASCII 30  = __RS__)
		    >+++++++        | Cell 3 is 7  (will be ASCII 70  = F)
			    >++++++++       | Cell 4 is 8  (will be ASCII 80  = P)
				    >++++++++++     | Cell 5 is 10 (will be ASCII 100 = d)
					    >+++++++++++    | Cell 6 is 11 (will be ASCII 110 = n)
						    <<<<<<-         | Decrements cell 0
							]                   | End of loop
							$                   | Prints the stack state (not a standard brainfuck command)
							@                   | Breakpoint (not a standard brainfuck command)
							>>>++.              | H
							>>+.                | E
							+++++++.            | L
							.                   | L
							>+.                 | O
							<<<<++.             | __SPC__
							>>+++++++.          | W
							>>.                 | O
							+++.                | R
							<.                  | L
							--------.           | D
							<<<+.               | !
							<+++.               | __CR__
							---.                | __LF__
							>>.                 | H
							>>+.                | E
							+++++++.            | L
							.                   | L
							>---.               | O
							<<<<-.              | __SPC__
							>>--.               | U
							>>-.                | N
							<---.               | I
							>++++++++.          | V
							<----.              | E
							>----.              | R
							+.                  | S
							<.                  | E
							<<<+.               | !
							<+++.               | __CR__
							---.                | __LF__
							$                   | Prints the stack state (not a standard brainfuck command)
							%                   | Resets the stack (not a standard brainfuck command)
							$  
