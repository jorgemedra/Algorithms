Stable Matching Algorithm.
=========================

  This algorithm use Arrays and List, according whith the book. In this case i prefered used a Stack Structure instead of a List Structure to implement the algorithm, but it still keep the *O(1)* execution time.

```

Build  preferences model, using the grids for women an men

At the begin all women and men are free

While there is man *m* who is free and hasn´t proposed every woman.

  Choose such a man m
  Let w be the highest-ranked woman in m's preference list to whom m has not yet proposed

  If w is free then
    (m,w) become engaged
  Else w is currently engaged to m´
    If w prefere m´ to m then
      m remain free
    Else
      (m,w) become engaged
      m´ become free
    End If
  End If
End While

Return the set S of engaged pairs
```


  To use it you must:
  1. set the amount of pairs, men-women to build a model with pre-data.
  2. Set the preference of each woman and man, using the grids that are available in the form. **Be careful to not repeat a man o woman in each preference list.**
  3. Once the preference lists are filled press the button *Run Algorithm*. The final match will appear into the left table.


# References

+ [Algorithm Design,  by Jon Kleinberg ](https://www.amazon.com.mx/Algorithm-Design-Jon-Kleinberg/dp/0321295358)
