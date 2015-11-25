

public class ListTest {
    public static void main(String[] args){
	int[] a1 = {2,5,8,4,3,7,6,7};
	NodeSLList list1 = new NodeSLList(a1); // test array constructor & add to tail
	list1.print(); // test print
	list1.removeFirstNode(); // test remove first node
	list1.print();
	System.out.println(list1.getSize()); // test get size
	list1.removeLastNode(); // test remove last node
	list1.print();


	NodeSLList list2 = new NodeSLList();
	Node n = new Node(5);
	list2.addToHead(n); // test add to head
	list2.print();

	list1.append(list2);
	list1.print();
    }
}