import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Hashtable;

public class Main {
	
	static int N = 5003;
	static int[] id = new int[N];
	static int[] sz = new int[N];
	static int max = 0;
	
	public static void main (String[] args) throws IOException {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        String line;
        String[] store;
      
        int c = 0;
        int r = 0;
        int i = 0;
        int j = 0;
        Hashtable<String, Integer> map = new Hashtable<String, Integer>();      
        
        while(true) {
        	line = buffer.readLine();
        	store = line.split(" ");
        	
        	c = Integer.parseInt(store[0]);
        	r = Integer.parseInt(store[1]);
        	
        	if (c == 0 && r == 0) 
        		break;
        	
        	map.clear();
        	max = 0;
        	
        	for (int k = 0; k < c; k++) {
				id[k] = k;
				sz[k] = 1;
				
				line = buffer.readLine().trim();
				map.put(line, k);
			}
        	
        	for (int k = 0; k < r; k++) {
        		line = buffer.readLine().trim();
        		store = line.split(" ");
        		
		      	i = map.get(store[0]);
            	j = map.get(store[1]);
                
            	if (i == j)
            		continue;
            	
                quick_weight_union(i , j);
			}
        	
        	
        	for(int k = 0; k < c; k++) {
        		max = Math.max(max, sz[k]);
        	}
        	
        	System.out.println(max);
        	line = buffer.readLine();
        }
    }
	
	private static int root(int i) {
		return i == id[i] ? i : (id[i] = root(id[i]));
	}
	
	public static void quick_weight_union(int p, int q) {
		int i = root(p);
		int j = root(q);
		
		if (i == j) {
			return;
		}
		
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
			//max = Math.max(max, sz[j]);
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
			//max = Math.max(max, sz[i]);
		}
	}
}


