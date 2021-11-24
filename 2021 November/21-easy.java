import java.util.*;
import java.io.*;

public class Main {
	
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());	
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i =0; i < n; i++){
			a[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i =0; i < n; i++){
			b[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i =0; i < n; i++){
			c[i] = Integer.parseInt(st.nextToken());
		}
		
		int[] cnt = new int[100001];
		for(int i = 0; i < n; i++){
			cnt[a[i]]++;
		}
		
		long ans = 0;
		for(int i = 0; i < n; i++){
			ans += cnt[b[c[i]-1]];
		}
		pw.println(ans);
		pw.close();
		
		
	}
}

