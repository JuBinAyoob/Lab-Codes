#include <stdio.h>
#include <string.h>

main()
{
	int p=0,q=1,r=2,s=3,t=4,u=5,v=6,ch;
	char str1[5]="DNKFG",str2[5]="AHGUI",str3[5]="RAMNO",str4[5]="GNEPH",str5[5]="ANFRG",str6[6]="CGAONS",str7[6]="HXCNMO";

	
	for(p=0;p<5;p++)
		for(q=0;q<5;q++)
			for(r=0;r<5;r++)
				for(s=0;s<5;s++)
					for(t=0;t<5;t++)
						for(u=0;u<6;u++)
							for(v=0,scanf("%d",&ch);v<6;v++)
								printf("%c %c %c %c %c %c %c\n",str1[p],str2[q],str3[r],str4[s],str5[t],str6[u],str7[v]);
}
