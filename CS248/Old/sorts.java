public class sorts
{
	private static int findmax(Comparable [] list, int last)
	{
		int max=0; // location of the max so far
		for(int j=1; j<=last; j++)
			if(list[j].compareTo(list[max])>0)
			// if( list[j] > list[max] )
				max=j;
		return max;
	}
	private static void swap(Object [] list, int x, int y)
	{
		Object tmp=list[x];
		list[x]=list[y];
		list[y]=tmp;
	}
	
	public static void selection(Comparable [] list)
	{
		for(int i=list.length-1; i>0; i--)
		{
			int maxpos=findmax(list,i);
			swap(list,maxpos,i);
		}
	}
	
	public static void bubble(Comparable [] list)
	{
		boolean done=false;
		while(!done)
		{
			done=true;
			for(int i=0; i+1<list.length; i++)
				//if( list[i] > list[i+1] )
				if(list[i].compareTo(list[i+1])>0)
				{ swap(list,i,i+1); done=false; }
				// if we swap, it's not sorted, so we're not done
		}
	}
	
	public static void insertion(Comparable [] list)
	{
		for(int i=1; i<list.length; i++)
		{
			Comparable itemtoinsert=list[i];
			int j;
			for(j=i-1; j>=0 && 
				//list[j]>itemtoinsert; j--)
				list[j].compareTo(itemtoinsert)>0; j--)
				{ list[j+1]=list[j]; }
			list[j+1]=itemtoinsert;
		}
	}
	
	public static void stripeinsertion(Comparable [] list,
		int gap, int offset)
	{
		for(int i=offset+gap; i<list.length; i=i+gap)
		{
			Comparable itemtoinsert=list[i];
			int j;
			for(j=i-gap; j>=0 && 
				//list[j]>itemtoinsert; j--)
				list[j].compareTo(itemtoinsert)>0; j=j-gap)
				{ list[j+gap]=list[j]; }
			list[j+gap]=itemtoinsert;
		}
	}
	
	public static void shell(Comparable [] list)
	{
		int gap=list.length/3;
		while(gap>=2)
		{
			for(int offset=0; offset<gap; offset++)
				stripeinsertion(list,gap,offset);
			gap=(int)(gap/2.2);
		}
		insertion(list);
	}
	
	public static void quick(Comparable [] list)
	{
		quickhelp(list,0,list.length-1);
	}
	
	private static void quickhelp(Comparable [] list,
		int start, int stop)
	{
		// base cases
		if(stop<=start) return; // size is 0 or 1
		if(start+1==stop) // size 2
		{
			if(list[start].compareTo(list[stop])>0)
				swap(list,start,stop);
			return;
		}
		// recursive case
		int pivotpos=partition(list,start,stop);
		quickhelp(list,start,pivotpos-1);
		quickhelp(list,pivotpos+1,stop);
	}
	
	private static int partition(Comparable [] list,
		int start, int stop)
	{
		Comparable pivot=list[stop];
		int fr=start;
		for(int i=start; i<stop; i++)
		{
			if(list[i].compareTo(pivot)<0)
			{
				swap(list,i,fr);
				fr++;
			}
		}
		swap(list,fr,stop);
		return fr;
	}
	
	public static void merge(Comparable [] list)
	{
		mergehelp(list,0,list.length-1);
	}
	
	private static void mergehelp(Comparable [] list,
		int start, int stop)
	{
		// base cases
		if(stop<=start) return; // size is 0 or 1
		if(start+1==stop) // size 2
		{
			if(list[start].compareTo(list[stop])>0)
				swap(list,start,stop);
			return;
		}
		// recursion
		int mid=(start+stop)/2;
		mergehelp(list,start,mid);
		mergehelp(list,mid+1,stop);
		domerge(list,start,mid,stop);
	}
	
	private static void domerge(Comparable [] list,
		int start, int mid, int stop)
	{
		Comparable [] dinosaur=new Comparable[stop-start+1];
		int left=start;
		int right=mid+1;
		for(int i=0; i<dinosaur.length; i++)
		{
			// right is empty OR left is not empty and left is smaller
			if(right>stop || left<=mid && 
				list[left].compareTo(list[right])<=0)
				dinosaur[i]=list[left++];
			else
				dinosaur[i]=list[right++];
		}
		for(int i=0; i<dinosaur.length; i++)
			list[start+i]=dinosaur[i];
	}
}