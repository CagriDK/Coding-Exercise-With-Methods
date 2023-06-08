#### Bir std::string nesnesi üzerinde aşağıdaki silme işlemlerini gerçekleştirmeniz gerekiyor:

01. Yazının ilk karakterini silin.
02. Yazının son karakterini silin.
03. Yazının ilk ve son karakterleri dışında tüm karakterlerini silin.
04. Yazının ikinci karakterini silin.
05. Yazının sondan ikinci karakterini silin.
06. idx yazının geçerli bir indeksi olmak üzere yazının *idx* indisli karakterini silin.
07. Yazıdaki ilk *a* karakterini silin.
08. Yazıdaki son *a* karakterini silin.
19. Yazıdaki tüm *a* karakterlerini silin.
10. Yazıdaki ilk *a* karakteri ile başlayan ve son *a* karakteri ile biten yazıyı silin.
11. Yazıdaki ilk *a* karakterinden önce gelen ve sonra gelen *2* karakteri silin.
12. Yazıda bulunan ilk *"kan"* yazısını silin
13. Yazıda bulunan son *"kan"* yazısını silin
14. Yazıda bulunan tüm *"kan"* yazılarını silin
15. Yazıda bulunan ilk rakam karakterini silin
16. Yazıda bulunan son rakam karakterini silin
17. Yazıdaki tüm rakam karakterlerini silin.
18. Yazının uzunluğu 1'den büyükse ve yazının ilk karakteri ile son karakteri aynı ise bunları silin.
19. Yazının uzunluğu 5'ten büyükse ve yazının ilk *3* karakteri ile son *3* karakteri aynı ise bunları silin.
20. Yazıdaki ardışık eşit karakterlerden sadece bir tane kalacak şekilde silme işlemi yapın. *(unique)*
21. Yazıdaki tüm boşluk *(whitespace)* karakterlerini silin.

**Aşağıdaki test kodunu kullanabilirsiniz:**

```
#include <string>
#include <iostream>

void print(const std::string &s)
{
	std::cout << "'" << s << "' [" << s.length() << "]\n";
}

int main()
{
	std::string s;

	std::cout << "bir yazi giriniz: ";
	std::getline(std::cin, s);
	print(s);
	///kod
	print(s);
}

```

//1.cevap s.erase(s.begin());
//2.cevap s.pop_back();
//3.cevap s.erase(s.begin()+1,s.end()-1);
//4.cevap s.erase(s.begin()+1);
//5.cevap s.erase(s.end()-1);
//6.cevap s.erase(idx,1);
//7.cevap s.erase(s.find_first_of("a"),1);
//8.cevap s.erase(s.find_last_of("a"),1);
//9.cevap std::remove(s.begin(),s.end(),'a');
//10.cevap s.erase(s.find_first_of("a")+1,s.find_last_of("a")-s.find_first_of("a")-1);
//11.cevap s.erase(s.find_first_of("a")-1,1); s.erase(s.find_first_of("a")+1,2);
//12.cevap s.erase(s.find("kan"),3);
//13.cevap s.erase(s.rfind("kan"),3);
//14.cevap while(s.find("kan") != std::string::npos) {s.erase(s.find("kan"),3);}
//15. cevap s.erase(s.find_first_of("0123456789"),1);
//16. cevap s.erase(s.find_last_of("0123456789"),1);
//17. cevap while(s.find_first_of("0123456789") != std::string::npos) {s.erase(s.find_first_of("0123456789"),1);}
//18. cevap if(s.size() > 1 && (s.at(0) == s.at(s.size()-1))){ s.erase(s.begin()); s.erase(s.end()-1);}
//19. cevap if(s.length() > 5 && s.substr(0,3) == s.substr(s.length()-3,3)){s.erase(0,3); s.erase(s.size()-3,3);}
//20. cevap	for(auto iter=s.begin();iter!=s.end();++iter){if(*(iter+1) == *(iter)){s.erase(iter);std::cout<<(*iter)<<"\n";}}
//21. cevap while(s.find(" ") != std::string::npos){s.erase(s.find(" "),1);}
