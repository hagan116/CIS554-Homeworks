

public class NodeSLList {
    private Node head;
    private Node tail;
    private int size;

    public NodeSLList(){
		head = tail = null;
		size = 0;
    }

    public NodeSLList(int[] a){
    	for (int i = 0; i < a.length; i++){
    		Node n = new Node(a[i]);
    		addToTail(n);
    	}
    }

    public NodeSLList(NodeSLList l){
    	Node temp = l.getHead();
    	for (int i = 0; i < l.getSize(); i++){
    		Node n = new Node(temp.getData());
    		addToTail(n);
    		temp = temp.getNext();
    	}
    }

    public Node getHead(){
    	return head;
    }

    public Node getTail(){
    	return tail;
    }

    public boolean isEmpty(){
    	return (head == null);
    }

    public void addToHead(Node n){
    	if (head == null){ // list is empty
    		head = tail = n;
    		size++;
    	}
    	else {
    		n.setNext(head);
    		head = n;
    		size++;
    	}
    }

    public void addToTail(Node n){
    	if (head == null){ // list is empty
    		head = tail = n;
    		size++;
    	}
    	else {
    		tail.setNext(n);
    		tail = n;
    		size++;
    	}
    }

    public int getSize(){
    	/*Node temp = head;
    	int size = 0;
    	while (temp != null){
    		temp = temp.getNext();
    		size++;
    	}*/
    	return size;
    }

    public Node removeFirstNode(){
    	if (head == null){
    		return null;
    	}
    	Node result = head;
    	head = head.getNext();
    	size--;
    	return result;
    }

    public Node removeLastNode(){
		if (head == null){
			return null;
		}
		Node temp = head;
		while (temp.getNext() != tail){
			temp = temp.getNext();
		}
		Node result = tail;
		tail = temp;
		tail.setNext(null);
		size--;
		return result;
	}

	public Node removeNode(int position){
		if (position <= 0){
			position = 1;
		}
		Node temp = head, prev = head;
		Node result =  new Node();
		for (int i = 1; i < position; i++){
			prev = temp;
			temp = temp.getNext();
			if (temp == tail){
				return removeLastNode();
			}
		}
		if (temp == head){
			return removeFirstNode();
		}

		prev.setNext(temp.getNext());
		result.setData(temp.getData());
		size--;
		return result;
	}

	public void print(){
		Node temp = head;
		while (temp != null){
			System.out.print(temp.getData() +  " ");
			temp = temp.getNext();
		}
		System.out.println();
	}

	public boolean equals(NodeSLList l){
		Node temp1 = head;
		Node temp2 = l.getHead();
		if (size != l.getSize()){
			return false;
		}
		for (int i = 0; i < size; i++){
			if (temp1.getData() != temp2.getData()){
				return false;
			}
			temp1 = temp1.getNext();
			temp2 = temp2.getNext();
		}
		return true;
	}

	public void append(NodeSLList l){
		tail.setNext(l.getHead());
	}
}