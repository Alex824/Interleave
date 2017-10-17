Alexander McLaughlin
Version 1.0.0

This program takes an input of two linked lists that are created in main, however, I generated these two lists based on two for loops which would give them distinguished node values. 

Something that will be worked on in the next version is evenly distributing the nodes of the second list passed into the interleave function across the first, or vice versa depending on the size of the list. As it stands, the list currently only supports every other node being one from each, but if one list is larger than the other, it is not evenly distributed but rather the larger list just has all of its remaining nodes that were not placed into the new interleaved list go directly after the interleaved nodes. 

In order to fix this I intend to check if one list is divisible by the other, and in doing so distribute the values accordingly in a more even fasion.

For instance, if there were two lists like this:

  +---+---+---+---+---+---+---+---+---+---+---+---+
1:| 7 | 8 | 9 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
  +---+---+---+---+---+---+---+---+---+---+---+---+

  +---+---+---+
2:| 4 | 5 | 6 |
  +---+---+---+

The current program distributes them like so:
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| 7 | 4 | 8 | 5 | 9 | 6 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
  ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
  1   2   1   2   1   2   1   1   1   1   1   1   1   1   1

Rather than the way I want to in my next update like so:

+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| 7 | 8 | 9 | 4 | 1 | 2 | 3 | 5 | 4 | 5 | 6 | 6 | 7 | 8 | 9 |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
  ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
  1   1   1   2   1   1   1   2   1   1   1   2   1   1   1

Which will alternate them based on one list's divisibility into another, making for a much better and more spread out interleaving of the linked lists.