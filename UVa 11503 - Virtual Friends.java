import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Hashtable;

public class Main {
	
	static int N = 200005;
	static int[] id = new int[N];
	static int[] sz = new int[N];
	
	public static void main (String[] args) throws IOException {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        String line;
        String[] names;
        int idx = 0;
        int t = 0;
        int n = 0;
        int i = 0;
        int j = 0;
        int l = 0;
        Hashtable<String, Integer> map = new Hashtable<String, Integer>();      
        
        t = Integer.parseInt(buffer.readLine());
        
        while (t-- > 0) {
        	n = Integer.parseInt(buffer.readLine());
        	l = 2*(n + 1);
        	map.clear();
        	idx = 0;
        	
        	for (int k = 0; k <= l; k++) {
				id[k] = k;
				sz[k] = 1;
			}
        	
        	for (int k = 0; k < n; k++) {
        		line = buffer.readLine().trim();
        		names = line.split(" ");
        		
        		if (!map.containsKey(names[0])) {
                	map.put(names[0], idx);
                	i = idx;
                	idx++;
                }
                else {
                	i = map.get(names[0]);
                }
                
                if (!map.containsKey(names[1])) {
                	map.put(names[1], idx);
                	j = idx;
                	idx++;
                }
                else {
                	j = map.get(names[1]);
                }
                
                quick_weight_union(i , j);
			}	
        }
    }
	
	private static int root(int i) {
		if (i == id[i])
			return i;
		
		return id[i] = root(id[i]);
	}
	
	public static void quick_weight_union(int p, int q) {
		int i = root(p);
		int j = root(q);
		
		if (i == j) {
			System.out.println(sz[i]);
			return;
		}
		
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
			System.out.println(sz[j]);
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
			System.out.println(sz[i]);
		}
	}
}


