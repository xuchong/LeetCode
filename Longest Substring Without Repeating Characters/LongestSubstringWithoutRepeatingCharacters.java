import java.util.HashMap;
import java.util.Scanner;

public class LongestSubstringWithoutRepeatingCharacters {
	public int lengthOfLongestSubstring(String s) {
			int start=0,end=1;
			int length=s.length();
			if(length==0)
				return 0;
			int index;
			String tmp;
			char character;
			int max=1;
			int tmplength=1;
			HashMap<Character,Integer>maps=new HashMap<Character,Integer>();
			maps.put(s.charAt(0), 0);
			while(end!=length&&start<end)
			{
				character=s.charAt(end);
				if(!maps.containsKey(character))
				{
					tmplength++;
					maps.put(character, end);
					if(tmplength>max)
						max=tmplength;
				}else
				{
					tmp=s.substring(start, end);
					index=tmp.indexOf(character);
					for(int i=start;i<=start+index;i++)
					{
						maps.remove(s.charAt(i));
					}
					start+=index+1;
					tmplength-=index;
					maps.put(character, end);
				}
				end++;
			}
	        return max;
	    }
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			String str = sc.nextLine();
			System.out.println(new LongestSubstringWithoutRepeatingCharacters().lengthOfLongestSubstring(str));
		}
	}
}
