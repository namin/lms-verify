/*@
predicate integers(int *start, int count) =
    count <= 0 ? true : integer(start, _) &*& integers(start + 1, count - 1);
@*/

/*@

lemma void split_integers_chunk(int *start, int i)
    requires integers(start, ?count) &*& 0 <= i &*& i <= count;
    ensures integers(start, i) &*& integers(start + i, count - i);
{
    if (i == 0) {
        close integers(start, 0);
    } else {
        open integers(start, count);
        split_integers_chunk(start + 1, i - 1);
        close integers(start, i);
    }
}

lemma void merge_integers_chunk(int *start)
    requires integers(start, ?i) &*& integers(start + i, ?count) &*& 0 <= i &*& 0 <= count;
    ensures integers(start, i + count);
{
    open integers(start, i);
    if (i != 0) {
        merge_integers_chunk(start + 1);
        close integers(start, i + count);
    }
}

@*/
