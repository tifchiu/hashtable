# hashtable
A simple implementation of hash tables (for practice purposes). The user can add people and their ages to a hash table and perform lookups, inserts, and deletions.
The hashing algorithm used simply iterates through the name, and for each letter adds its ASCII value to the hash value and then multiplies the resulting hash value by the ASCII value. This number, modulo <TABLE_SIZE>, is the final hash value for that name.  

## Master branch
Here, we deal with collisions by linking together names that map to the same hash value via a linked list. This is called external chaining. In comparison to linear probing, it has reduced cognitive complexity and as a plus, the size of the hash table grows as necessary.  
The downside to the latter point is if the size of our hash table M is small compared to the number of elements N, then our operations will be as if our data was in a linked list. O(n) time !  
However, if our hash function is uniform and the size of our table is appropriate, then we can expect the following metrics:
* The average length of a linked list in the table is N/M
* The load factor is also N/M
* The time-complexity of the operations is in general O(N/M)

## v1 branch
This branch, for illustrative purposes, does not handle collisions at all. If a position in the table is already occupied, we do not insert the person's information. Obviously this is not ideal, as we never want our data to be saved only "some of the time."

## v2 branch
Here, we deal with collisions via linear probing. If the position we want to insert in is occupied, we look for the next available position. This has the benefit of an easy implementation, however as the size of our data grows, we begin to see operations taking O(n) time.  
Moreover, the size of our table is fixed. If we attempt to insert the (M+1)-th person into the hash table, we will proble every position in the table only to realize that there is no room. Again, not all our data will be represented in the table and this is not ideal.
