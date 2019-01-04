
# include <istream>

# include <ahSort.H>
# include <tpl_dynMat.H>
# include <tpl_tree_node.H>
# include <generate_tree.H>

# include <dictnode.H>

# include <grid.H>
# include <word-find.H>


int main()
{	

	WordFind d(    0   1   2   3   4   5   6   7   8   9  10  11 
 0  e   i   n   d   a   n   t   h   a   o   r   o 
 1  b   f   c   h   r   a   t   b   l   o   i   p 
 2  i   a   r   a   k   g   o   e   a   t   i   o 
 3  t   d   c   c   e   g   o   r   u   a   r   l 
 4  r   i   o   n   a   r   u   t   e   a   e   o 
 5  e   c   n   t   l   i   n   i   n   e   i   p 
 6  k   n   i   e   t   g   e   c   g   o   n   o 
 7  m   u   i   u   a   p   a   l   i   r   i   m 
 8  r   c   p   c   i   c   a   o   t   v   u   t 
 9  m   a   s   m   o   o   r   a   f   m   s   r 
10  e   t   s   e   n   n   m   c   e   n   n   t 
11  h   e   s   i   y   o   i   n   a   t   i   i); 
	Cnode a='a';
	Cnode * r= &a;
	d.legal_moves(0,0);
	d.extract_word_from_stack();
  d.search(0,0, r);
}
