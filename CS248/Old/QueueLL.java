public class QueueLL implements Queue
{
	private class node
	{
		public Object data;
		public node next;
	}
	node front, back;
	int count;
	
	public QueueLL()
	{
		makeEmpty();
	}
	
	
	public void enqueue(Object x)
	{
		node newnode=new node();
		newnode.data=x;
		newnode.next=null;
		if(!isEmpty())
			back.next=newnode;
		else
			front=newnode;
		back=newnode;
		count++;
	}
	public Object dequeue()
	{
		if(isEmpty()) return null;
		Object saveddata=front.data;
		front=front.next;
		count--;
		return saveddata;
	}
	public Object getFront()
	{
		if(isEmpty()) return null;
		return front.data;
	}
	public boolean isEmpty() { return count<=0; }
	public boolean isFull() { return false; }
	public int size() { return count; }
	public void makeEmpty()
	{
		front=back=null;
		count=0;
	}
}