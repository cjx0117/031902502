﻿//考虑插入其他字符、拼音、首字母，但是因为utf-8和拼音的对应表太长了没写完，所以文件中只要输入未收录的汉字就会无限循环。。。
#include<iostream>
#include<fstream>
#include <cstdio>
#include<cmath>
#include<iomanip>
#include <algorithm>
#include<cstring>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
const int num[196][3] = { {-28, -72, -128}, {-28, -72, -127}, {-28, -72, -125}, {-28, -72, -121}, {-28, -72, -120}, {-28, -72, -119}, {-28, -72, -118}, {-28, -72 ,-117}, { -28 ,-72, -116}, {-28, -72, -115}, {-28, -72 ,-114}, {-28, -72, -112}, {-28, -72,-111},
	{-28,-72,-109},{-28,-72,-108},{-28,-72,-107},{-28,-72,-106},{-28,-72,-104},{-28,-72,-103},{-28,-72,-102},{-28,-72,-101},
	{-28,-72,-100},{-28,-72,-99},{-28,-72,-98},{-28,-72,-94},{-28,-72,-92},{-28,-72,-91},{-28,-72,-89},{-28,-72,-88},{-28,-72,-86},
	{-28,-72,-85},{-28,-72,-84},{-28,-72,-83},{-28,-72,-80},{-28,-72,-78},{-28,-72,-76},{-28,-72,-74},{-28,-72,-72},{-28,-72,-71},
	{-28,-72,-70},{-28,-72,-69},{-28,-72,-67},{-28,-72,-66},{-28,-72,-65},{-28,-71,-125},{-28,-71,-123},{-28,-71,-121},{-28,-71,-120},
	{-28,-71,-119},{-28,-71,-117},{-28,-71,-116},{-28,-71,-115},{-28,-71,-114},{-28,-71,-113},{-28,-71,-112},{-28,-71,-110},
	{-28,-71,-109},{-28,-71,-108},{-28,-71,-106},{-28,-71,-104},{-28,-71,-103},{-28,-71,-100}, {-28,-71,-99}, {-28,-71,-98},
	{-28,-71,-97}, {-28,-71,-96}, {-28,-71,-95}, {-28,-71,-90}, {-28,-71,-87}, {-28,-71,-80}, {-28,-71,-79}, {-28,-71,-77},
	{-28,-71,-66}, {-28,-70,-122},
	{-28,-70,-120},{-28,-70,-119},{-28,-70,-117},{-28,-70,-116},{-28,-70,-115},{-28,-70,-114},{-28,-70,-113},{-28,-70,-111},
	{-28,-70,-110},{-28,-70,-109},{-28,-70,-108},{-28,-70,-107},{-28,-70,-104},{-28,-70,-102},{-28,-70,-101},{-28,-70,-97},{-28,-70,-96},
	{-28,-70,-95},{-28,-70,-94},{-28,-70,-92},{-28,-70,-91},{-28,-70,-90},{-28,-70,-89},{-28,-70,-88},{-28,-70,-87},{-28,-70,-85},
	{-28,-70,-84},{-28,-70,-83},{-28,-70,-82},{-28,-70,-78},{-28,-70,-77},{-28,-70,-75},{-28,-70,-70},{-28,-70,-69},{-28,-70,-65},
	{-28,-69,-128},{-28,-69,-127},{-28,-69,-126},{-28,-69,-125},{-28,-69,-124},{-28,-69,-123},{-28,-69,-122},{-28,-69,-121},
	{-28,-69,-119},{-28,-69,-118},{-28,-69,-117},{-28,-69,-115},{-28,-69,-114},{-28,-69,-111},{-28,-69,-109},{-28,-69,-108},{-28,-69,-107},
	{-28,-69,-106},{-28,-69,-105},{-28,-69,-104},
	{-28,-69,-103},{-28,-69,-99},{-28,-69,-98},{-28,-69,-97},{-28,-69,-95},{-28,-69,-93},{-28,-69,-92},{-28,-69,-91},{-28,-69,-88},
	{-28,-69,-86},{-28,-69,-85},{-28,-69,-84},{-28,-69,-80},{-28,-69,-78},{-28,-69,-77},{-28,-69,-75},{-28,-69,-74},{-28,-69,-73},
	{-28,-69,-69},{-28,-69,-67},{-28,-69,-65},{-28,-68,-127},{-28,-68,-119},{-28,-68,-118},{-28,-68,-115},{-28,-68,-114},{-28,-68,-113},
	{-28,-68,-112},{-28,-68,-111},{-28,-68,-105},{-28,-68,-104},{-28,-68,-103},{-28,-68,-102},{-28,-68,-101},{-28,-68,-98},
	{-28,-68,-97},{-28,-68,-96},{-28,-68,-94},{-28,-68,-92},{-28,-68,-91},{-28,-68,-90},{-28,-68,-89},{-28,-68,-86},{-28,-68,-85},
	{-28,-68,-81},{-28,-68,-80},{-28,-68,-78},{-28,-68,-76},{-28,-68,-74},{-28,-68,-72},{-28,-68,-70},{-28,-68,-68},{-28,-68,-67},
	{-28,-67,-125},{-28,-67,-122},
	{-28,-67,-115},{-28,-67,-114},{-28,-67,-113},{-28,-67,-112},{-28,-67,-111},{-28,-67,-109},{-28,-67,-107},{-28,-67,-105},
	{-28,-67,-104},{-28,-67,-103},{-28,-67,-102},{-28,-67,-101} };/*,{-28,-67,-100},{-28,-67,-99,},{-28,-67,-98},{-28,-67,-97},{-28,-67,-96},
	{-28,-67,-93},{-28,-67,-92},{-28,-67,-91},{-28,-67,-89},{-28,-67,-87},{-28,-67,-84},{-28,-67,-81},{-28,-67,-80},{-28,-67,-77},
	{-28,-67,-76},{-28,-67,-74},{-28,-67,-69},{-28,-67,-68},{-28,-67,-66},{-28,-67,-65},{-28,-66,-125},{-28,-66,-124},{-28,-66,-120},
	{-28,-66,-119},{-28,-66,-117},{-28,-66,-115},{-28,-66,-113},{-28,-66,-111},{-28,-66,-108},{-28,-66,-105},{-28,-66,-101},
	{-28,-66,-99},{-28,-66,-96},{-28,-66,-93},{-28,-66,-91},{-28,-66,-90},{-28,-66,-89},{-28,-66,-88},{-28,-66,-87},{-28,-66,-86},
	{-28,-66,-84},{-28,-66,-82},{-28,-66,-81},
	{-28,-66,-75},{-28,-66,-65},{-28,-65,-125},{-28,-65,-124},{-28,-65,-123},{-28,-65,-118},{-28,-65,-114},{-28,-65,-113},{-28,-65,-112},
	{-28,-65,-111},{-28,-65,-105},{-28,-65,-104},{-28,-65,-102},{-28,-65,-100},{-28,-65,-99},{-28,-65,-98},{-28,-65,-97},{-28,-65,-95},
	{-28,-65,-93},{-28,-65,-90},{-28,-65,-88},{-28,-65,-87},{-28,-65,-86},{-28,-65,-83},{-28,-65,-82},{-28,-65,-81},{-28,-65,-79},
	{-28,-65,-77},{-28,-65,-72},{-28,-65,-70},{-28,-65,-66},{-27,-128,-116},{-27,-128,-115},{-27,-128,-113},{-27,-128,-110},{-27,-128,-108},
	{-27,-128,-104},{-27,-128,-103},{-27,-128,-102},{-27,-128,-100},{-27,-128,-97},{-27,-128,-95},{-27,-128,-91},{-27,-128,-90},
	{-27,-128,-88},{-27,-128,-87},{-27,-128,-86},{-27,-128,-84},{-27,-128,-83},{-27,-128,-82},{-27,-128,-70},{-27,-128,-68},
	{-27,-128,-66},{-27,-127,-125},{-27,-127,-121},
	{-27,-127,-120},{-27,-127,-116},{-27,-127,-114},{-27,-127,-113},{-27,-127,-107},{-27,-127,-102},{-27,-127,-100},{-27,-127,-91},
	{-27,-127,-84},{-27,-127,-74},{-27,-127,-73},{-27,-127,-69},{-27,-127,-66},{-27,-127,-65},{-27,-126,-128},{-27,-126,-123},
	{-27,-126,-120},{-27,-126,-115},{-27,-126,-93},{-27,-126,-91},{-27,-126,-89},{-27,-126,-88},{-27,-126,-87},{-27,-126,-84},
	{-27,-126,-78},{-27,-126,-70},{-27,-126,-69},{-27,-125,-113},{-27,-125,-106},{-27,-125,-102},{-27,-125,-90},{-27,-125,-89},
	{-27,-125,-84},{-27,-125,-83},{-27,-125,-82},{-27,-125,-77},{-27,-125,-75},{-27,-125,-69},{-27,-124,-122},{-27,-124,-121},{-27,-124,-117},
	{-27,-124,-110}
	,{-27,-124,-95},{-27,-124,-65},{-27,-123,-128},{-27,-123,-127},{-27,-123,-125},{-27,-123,-124},{-27,-123,-123},{-27,-123,-122},
	{-27,-123,-120},{-27,-123,-119},{-27,-123,-117},{-27,-123,-115},{-27,-123,-111},{-27,-123,-108},{-27,-123,-107},{-27,-123,-106},
	{-27,-123,-102},{-27,-123,-100},{-27,-123,-94},{-27,-123,-91},{-27,-123,-88},{-27,-123,-85},{-27,-123,-84},{-27,-123,-83},{-27,-123,-82},
	{-27,-123,-80},{-27,-123,-79},{-27,-123,-77},{-27,-123,-76},{-27,-123,-75},{-27,-123,-74},{-27,-123,-73},{-27,-123,-72},{-27,-123,-71},
	{-27,-123,-69},{-27,-123,-68}
	,{-27,-123,-67},{-27,-122,-128},{-27,-122,-127},{-27,-122,-126},{-27,-122,-123},{-27,-122,-120},{-27,-122,-119},{-27,-122,-116},
	{-27,-122,-115},{-27,-122,-110},{-27,-122,-107},{-27,-122,-106},{-27,-122,-105},{-27,-122,-103},{-27,-122,-101},{-27,-122,-100},
	{-27,-122,-96},{-27,-122,-94},{-27,-122,-92},{-27,-122,-91},{-27,-122,-85},{-27,-122,-84},{-27,-122,-81},{-27,-122,-80},
	{-27,-122,-79},{-27,-122,-78},{-27,-122,-77},{-27,-122,-75},{-27,-122,-74},{-27,-122,-73},{-27,-122,-69},{-27,-122,-68},
	{-27,-122,-67},{-27,-121,-128},{-27,-121,-124},{-27,-121,-122}
	,{-27,-121,-121},{-27,-121,-119},{-27,-121,-117},{-27,-121,-116},{,-27,-121,-113},{-27,-121,-111},{-27,-121,-101},{-27,-121,-99},{-27,-121,-96},{-27,-121,-95},{-27,-121,-92},{-27,-121,-85},{-27,-121,-83},
	{-27,-121,-81},{-27,-121,-80},{-27,-121,-77},{-27,-121,-75},{-27,-121,-74},{-27,-121,-72},{-27,-121,-71},{-27,-121,-70},{-27,-121,-69},
	{-27,-121,-68},{-27,-121,-67},{-27,-121,-65},{-27,-120,-128},{-27,-120,-127},{-27,-120,-126},{-27,-120,-125},{-27,-120,-122},{-27,-120,-121},
	{-27,-120,-120},{-27,-120,-118},{-27,-120,-115},{-27,-120,-114},{-27,-120,-111}
	,{-27,-120,-110},{-27,-120,-106},{-27,-120,-105},{-27,-120,-104},{-27,-120,-103},{-27,-120,-102},{-27,-120,-101},{-27,-120,-99},
	{-27,-120,-96},{-27,-120,-92},{-27,-120,-88},{-27,-120,-87},{-27,-120,-85},{-27,-120,-83},{-27,-120,-82},{-27,-120,-80},{-27,-120,-77},
	{-27,-120,-74},{-27,-120,-73},{-27,-120,-72},{-27,-120,-71},{-27,-120,-70},{-27,-120,-69},{-27,-120,-67},{-27,-120,-65},{-27,-119,-128},
	{-27,-119,-127},{-27,-119,-126},{-27,-119,-125},{-27,-119,-118},{-27,-119,-116},{-27,-119,-115},{-27,-119,-112},{-27,-119,-111},
	{-27,-119,-108},{-27,-119,-106}
	,{-27,-119,-100},{-27,-119,-98},{-27,-119,-95},{-27,-119,-91},{-27,-119,-89},{-27,-119,-87},{-27,-119,-86},{-27,-119,-81},{-27,-119,-78},
	{-27,-119,-67},{-27,-119,-65},{-27,-118,-127},{-27,-118,-126},{-27,-118,-120},{-27,-118,-112},{-27,-118,-109},{-27,-118,-101},{-27,-118,-99},
	{-27,-118,-98},{-27,-118,-97},{-27,-118,-96},{-27,-118,-95},{-27,-118,-94},{-27,-118,-93},{-27,-118,-88},{-27,-118,-87},{-27,-118,-86},
	{-27,-118,-85},{-27,-118,-84},{-27,-118,-83},{-27,-118,-79},{-27,-118,-78},{-27,-118,-77},{-27,-118,-66},{-27,-118,-65},{-27,-117,-125},
	{-27,-117,-121},{-27,-117,-119},{-27,-117,-117},{-27,-117,-112},{-27,-117,-110},{-27,-117,-106},{-27,-117,-104},{-27,-117,-97},{-27,-117,-92},
	{-27,-117,-80},{-27,-117,-71},{-27,-117,-70},{-27,-117,-66},{-27,-117,-65},{-27,-116,-128},{-27,-116,-123},{-27,-116,-122},{-27,-116,-120},
	{-27,-116,-115},{-27,-116,-113},{-27,-116,-112},{-27,-116,-107},{-27,-116,-106},{-27,-116,-105},{-27,-116,-103},{-27,-116,-102},{-27,-116,-99},
	{-27,-116,-96},{-27,-116,-95},{-27,-116,-93},{-27,-116,-90},{-27,-116,-86},{-27,-116,-82},{-27,-116,-71},{-27,-116,-70},{-27,-116,-69},
	{-27,-116,-66},{-27,-116,-65},{-27,-115,-127},{-27,-115,-125},{-27,-115,-123},{-27,-115,-121},{-27,-115,-120},{-27,-115,-119},{-27,-115,-118},
	{-27,-115,-114},{-27,-115,-113},{-27,-115,-111},{-27,-115,-110},{-27,-115,-109},{-27,-115,-107},{-27,-115,-106},{-27,-115,-105},{-27,-115,-102},
	{-27,-115,-100},{-27,-115,-98},{-27,-115,-97},{-27,-115,-96},{-27,-115,-95},{-27,-115,-94},{-27,-115,-93},{-27,-115,-92},{-27,-115,-90},
	{-27,-115,-89},{-27,-115,-87},{-27,-115,-85},{-27,-115,-82},{-27,-115,-81},{-27,-115,-80},{-27,-115,-79},{-27,-115,-77},{-27,-115,-76},
	{-27,-115,-75},{-27,-115,-73},{-27,-115,-72},{-27,-115,-70},{-27,-115,-65},{-27,-114,-126},{-27,-114,-124},{-27,-114,-123},{-27,-114,-122},
	{-27,-114,-119},{-27,-114,-117},{-27,-114,-116},{-27,-114,-115},{-27,-114,-107},{-27,-114,-104},{-27,-114,-102},{-27,-114,-99},
	{-27,-114,-97},{-27,-114,-94},{-27,-114,-93},{-27,-114,-91},{-27,-114,-90},{-27,-114,-88},{-27,-114,-87},{-27,-114,-82},{-27,-114,-74},
	{-27,-114,-69},{-27,-114,-65},{-27,-113,-127},{-27,-113,-126},{-27,-113,-120},{-27,-113,-119},{-27,-113,-118},{-27,-113,-117},
	{-27,-113,-116},{-27,-113,-115},{-27,-113,-111},{-27,-113,-108},{-27,-113,-106},{-27,-113,-105},{-27,-113,-104},{-27,-113,-103},
	{-27,-113,-101},{-27,-113,-97},{-27,-113,-96},{-27,-113,-93},{-27,-113,-92},{-27,-113,-91},{-27,-113,-90},{-27,-113,-88},{-27,-113,-87},
	{-27,-113,-86},{-27,-113,-85},{-27,-113,-84},{-27,-113,-83},{-27,-113,-82},{-27,-113,-81},{-27,-113,-80},{-27,-113,-79},{-27,-113,-78},
	{-27,-113,-77},{-27,-113,-75},{-27,-113,-74},{-27,-113,-73},{-27,-113,-72},{-27,-113,-71},{-27,-113,-69},{-27,-113,-68},{-27,-113,-67},
	{-27,-112,-127},{-27,-112,-125},{-27,-112,-124},{-27,-112,-122},{-27,-112,-120},{-27,-112,-119},{-27,-112,-118},{-27,-112,-116},{-27,-112,-115},
	{-27,-112,-114},{-27,-112,-113},{-27,-112,-112},{-27,-112,-111},{-27,-112,-110},{-27,-112,-109},{-27,-112,-107},{-27,-112,-106},
	{-27,-112,-105},{-27,-112,-101},{-27,-112,-99},{-27,-112,-98},{-27,-112,-97},{-27,-112,-96},{-27,-112,-95},{-27,-112,-93},{-27,-112,-90},
	{-27,-112,-89},{-27,-112,-88},{-27,-112,-87},{-27,-112,-85},{-27,-112,-84},{-27,-112,-83},{-27,-112,-82},{-27,-112,-81},{-27,-112,-79},
	{-27,-112,-78},{-27,-112,-76},{-27,-112,-75},{-27,-112,-72},{-27,-112,-71},{-27,-112,-69},{-27,-112,-68},{-27,-112,-66},{-27,-111,-128},
	{-27,-111,-125},{-27,-111,-122},{-27,-111,-120},{-27,-111,-118},{-27,-111,-117},{-27,-111,-112},{-27,-111,-110},{-27,-111,-109},{-27,-111,-108},{-27,-111,-107},
	{-27,-111,-106},{-27,-111,-105},{-27,-111,-104},{-27,-111,-103},{-27,-111,-101,},{-27,-111,-100},{-27,-111,-94},{-27,-111,-92},{-27,-111,-90},
	{-27,-111,-88},{-27,-111,-79},{-27,-111,-78},{-27,-111,-77},{-27,-111,-75},{-27,-111,-74},{-27,-111,-73},{-27,-111,-72},{-27,-111,-69},
	{-27,-111,-68},{-27,-111,-67},{-27,-110,-128},{-27,-110,-126},{-27,-110,-124},{-27,-110,-122},{-27,-110,-117},{-27,-110,-116},{-27,-110,-114},
	{-27,-110,-113},{-27,-110,-112},{-27,-110,-110},{-27,-110,-108},{-27,-110,-107},{-27,-110,-106},{-27,-110,-103},{-27,-110,-102},{-27,-110,-101},
	{-27,-110,-99},{-27,-110,-93},{-27,-110,-92},{-27,-110,-90},{-27,-110,-89},{-27,-110,-88},{-27,-110,-87},{-27,-110,-86},{-27,-110,-85},
	{-27,-110,-84},{-27,-110,-83},{-27,-110,-81},{-27,-110,-79},{-27,-110,-77},{-27,-110,-76},{-27,-110,-72},{-27,-110,-69},{-27,-110,-67},
	{-27,-110,-65},{-27,-109,-128},{-27,-109,-127},{-27,-109,-126},{-27,-109,-124},{-27,-109,-122},{-27,-109,-121},{-27,-109,-120},
	{-27,-109,-119},{-27,-109,-116},{-27,-109,-115},{-27,-109,-114},{-27,-109,-113},{-27,-109,-112},{-27,-109,-111},{-27,-109,-110},
	{-27,-109,-109},{-27,-109,-108},{-27,-109,-107},{-27,-109,-105},{-27,-109,-103},{-27,-109,-102},{27,-109,-100},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}};*/
	const string spell[196] = { "yi","ding","qi","wan","zhang","san","shang","xia","qi","bu","yu","gai","chou","zhuan","qie","pi","shi","qiu","bing","ye","cong","dong","si",
	"cheng","diu","liang","yan","sang","gun","ge","ya","pan","zhong","feng","chuan","lin","zhu","wan","dan","wei","zhu","li","ju","pie","nai","jiu",
	"tuo","me" ,"yi","zhi","wu","zha","hu","fa","le","ping","pang","qiao","guai","cheng","yi",
	"mie","jiu","qi","ye","xi","xiang","shu","ji","mai","luan","ru","qian","le","yu","zheng","shi","er","chu","yu","kui","yun","hu","qi","wu","jing","gen","ya","xie","ji","tou","wang","kang","jiao","hai","yi","zhan","heng","mu","xiang","jing","ting","liang","qin","hao","xie","ren","ren","yi","shen","ren","le","ding","ze","jin","pu","chou","zhang","jin","jie","ren","cong","lun","cang","zai","shi","ta","zhang","fu","xian","tou","ren","qian","ge","dai","ling","yi","san","yi","mu","men","yang","zhong","pi","wu","jian","jia","ren","fen","fang","qi","kang","yi","wu","ji","fu","fa","xiu","zhong","you","huo","hui","yu","san","wei","chuan","ya","shang","chang","lun","cang","wei","zhu","bo","gu","ni","ban","ling","shen","ci","si","jia","dian","dan","wei","di","zhu","zuo","you","ti","he","tuo","she","yu","yi","fo" };/*, "zuo", "gou", "ning", "tong", "ni", "yong", "wa", "qian", "ka", "pei", "lao", "yang", "bai", "jia", "er", "ji", "tiao", "jiao", "yi", "shi", "kan", "zhi", "chi", "kua", "li", "shi", "zhu", "you", "mou", "tong", "gong", "yi", "xia", "lv", "jiao", "zhen", "ce", "qiao", "kuai", "chai", "nong", "hui", "hou", "qin", "bian", "cu", "e", "qiu", "jun", "zu", "qiao", "li", "yong", "su", "fu", "li", "ping", "bao", "yu", "si", "xin", "yu", "chou",
"yan","lia","li","jian","xiu","fu","ju","pai","feng","an","bi","guan","bei","shu","dao","jue","tang","hou","yi","ti","jie","chang","kong","juan","ju","qian","ni","zhuo","wo","luo","zhai","zhi","qing","yan","jia","jie","ruo","wei","pian","xie","zuo","ting",
"jian","zong","ou","tou","lou","fen","chang","kui","fu","li","bang","dai","tang","bin","chu","nuo","cui","ao","chi","sha","xiang","xi","liao","jiu","seng","qiao","jian","tong","su","jiang","pi","jing","xuan","dan","ru","lei","er","wu","yun","yuan","xiong","chong","zhao","xian","guang","ke","mian","dui","tu","si","yan","dang","dou","jing","ru","quan","ba","gong","liu","xi","lan","gong","guan","xing","bing","qi","ju","dian","zi","yang","jian","shou","ji","chan","jiong","nei","gang","ran","ce","zai","mao","mian","mi","hang","xie","jun","nong","guan","zhong","yuan","ming","bing","dong","feng","bing","hu","chong","jue","kuang","ye","leng","dong","xian","lie","jing","qi","zhun","song","liang","diao","ling","jian","cou","lin","ning","ji","fan","feng","fu","ping","kai","huang","deng","kan","xiong","tu","ao",
"mie","jiu","qi","ye","xi","xiang","shu","ji","mai","luan","ru","qian","le","yu","zheng","shi","er","chu","yu","kui","yun","hu","qi","wu","jing","gen","ya","xie","ji","tou","wang","kang","jiao","hai","yi","zhan","heng","mu","xiang","jing","ting","liang","qin","hao","xie","ren","ren","yi","shen","ren","le","ding","ze","jin","pu","chou","zhang","jin","jie","ren","cong","lun","cang","zai","shi","ta","zhang","fu","xian","tou","ren","qian","ge","dai","ling","yi","san","yi","mu","men","yang","zhong","pi","wu","jian","jia","ren","fen","fang","qi","kang","yi","wu","ji","fu","fa","xiu","zhong","you","huo","hui","yu","san","wei","chuan","ya","shang","chang","lun","chen","wei","zhu","bo","gu","ni","ban","ling","shen","ci","si","jia","dian","dan","wei","di","zhu","zuo","you","ti","he","tuo","she","yu","yi","fo"
};*/
struct mapping//用来建立敏感词树
{
	string dat;//记录敏感词英文单词的一个字母或者中文一个字的拼音
	mapping* next = NULL, * nei = NULL;//next指向下一个字母或者拼音，nei指向该该位置其他可能出现的敏感词的一部分
	bool isc;
};
struct rela//记录原文和转化完的句子的对应关系
{
	int  beg,end;//记录该段字符串在原文中的起始位置和结束位置
	string dat;//记录该字符串
	bool isc=false;
	rela* next = NULL;
};
struct sto//存储敏感词结果
{
	int line, end;//line记录所在行数，end记录该敏感词出现的最后一个字节的后一位
	string sw1, sw2;//sw1为敏感词，sw2为包含敏感词的原文
	sto* next = NULL;
}*store = new sto, * sto2 = store, * sto3;
bool cword(int x)//判断是否是汉字
{
	if (x <=127&&x>=0)
		return false;
	else
		return true;
}
int sear(int x,int y,int z)//将中文转化为拼音，二分搜索，x，y，z是汉字三个字节转化成的补码值
{
	int low = 0, high = 195, mid = (low + high) / 2;
	if (num[high][0] == x && num[high][1] == y && num[high][2] == z)
		return high;
	while (low<high)
	{
		if (num[mid][0] > x || (num[mid][0] == x && num[mid][1] > y) || (num[mid][0] == x && num[mid][1] == y && num[mid][2] > z))
			high = mid;
		else if (num[mid][0] == x && num[mid][1] == y && num[mid][2] == z)
			break;
		else
			low = mid;
		mid = (high + low) / 2;
	}
	return mid;
}
rela* trans(string linestr)//转化字符串，去除除汉字，英文和数字以外字符，保存在链表out中，保留位置映射，输入是文件的一行原文
{
	int i, len = linestr.length(), x;
	rela* out2, * out3, * out;
	out = new rela;
	out2 = out;
	for (i = 0; i < len; )
	{
		if (linestr[i] >= 0 && linestr[i] < 128)//保留英文和数字
		{
			if ((linestr[i] <= 122 && linestr[i] >= 97) || (linestr[i] <= 57 && linestr[i] >= 48))
			{
				out3 = new rela;
				out3->dat = linestr[i];
				out3->beg = i;
				out3->end = i;
				out2->next = out3;
				out2 = out3;
			}
			else if (linestr[i] <= 90 && linestr[i] >= 65)//大写
			{
				out3 = new rela;
				out3->dat = linestr[i] + 32;
				out3->beg = i;
				out3->end = i;
				out2->next = out3;
				out2 = out3;
			}
			i++;
		}
		else//保留中文
		{
			if (i + 2 < len && cword(linestr.at(i)))
			{
				out3 = new rela;
				out3->dat = spell[sear(linestr[i],linestr[i+1], linestr[i+2])];
				out3->beg = i;
				out3->end = i + 2;
				out3->isc = true;
				out2->next = out3;
				out2 = out3;
				i += 3;
			}
		}
	}
	return out->next;
}
mapping* cretree(string x, int i, mapping* root, int len)//递归将敏感词并入树中,返回根节点root，x为文件的一行字符串，i为当前x的字节位置，root为当前节点指针，len为x的长度
{
	if (i >= len)
		return NULL;
	mapping* p1 = root;
	string s=x.substr(i,1);
	int count = 1;//s的长度
	bool isc = false;
	if (i + 2 < len && cword(x.at(i)))//判断为汉字，s改为对应拼音
	{
		s = spell[sear(x.at(i),x.at(i+1),x.at(i+2))];
		count = 3;
		isc = true;
	}
	if (p1 && p1->dat == s)//树中已经有该部分内容
	{
		if (p1->next)//当前节点有子节点则继续搜索
		{
			cretree(x, i + count, p1->next, len);
		}
		else//当前节点无子节点则访问next空节点并返回指针
		{
			p1->next = cretree(x, i + count, p1->next, len);
		}
	}
	else if (p1 && p1->dat != s)//当前节点内容与x[i]不同
	{
		if (p1->nei)//有邻居则向邻居搜索
			cretree(x, i, p1->nei, len);
		else//无邻居则访问nei空节点并返回指针
			p1->nei = cretree(x, i, p1->nei, len);
	}
	else if (!p1)//当前节点为空，建立节点，并返回指针，若字符串x未完则继续向下访问next空节点
	{
		p1 = new mapping;
		p1->dat = s;
		p1->next = cretree(x, i + count, p1->next, len);
		p1->isc = isc;
	}
	return p1;
}
int com(mapping* root, rela* outx, string sw,int end)//查敏感词，root为敏感词树当前节点指针，outx为原文映射链表当前指针，sw为目前已经搜索到的敏感词分片,end为当前原文最后一个字节位置
{
	if (outx->dat >= "0" && outx->dat <= "9" && !root->isc)//若数字在英文中间则跳过
		return com(root, outx->next, sw, end);
	if (outx->dat == root->dat)//当前outx所指的内容为敏感词分片
	{
		if (outx->beg - end - 1 > 20)
			return 0;
		if (root->next && outx->next)//两者都还有后续部分，继续向下比较
		{
			return com(root->next, outx->next, sw + root->dat,outx->end);
		}
		else if (root->next)//敏感词还有后续分片，但该行原文已经没有有效部分，说明这段字符串不是敏感词
		{
			return 0;
		}
		else//敏感词已经到达叶节点，敏感词完整找到，这段字符串是敏感词，记录
		{
			sto3 = new sto;
			sto3->sw1 = sw + root->dat;
			sto3->end = outx->end+1;
			return 1;
		}
	}
	else if (!outx->isc)//汉字拼音或首字母情况
	{
		while (root)
		{
			if (outx->dat == root->dat.substr(0, 1))
				break;
			root = root->nei;
		}
		if (!root)//没有对应首字母
			return 0;		
		if (!outx->next&&root->next)//没有完整敏感词
			return 0;
		else if (!outx->next && !root->next)//完整敏感词
		{
			sto3 = new sto;
			sto3->sw1 = sw + root->dat;
			sto3->end = outx->end + 1;
			return 1;
		}
		else if (outx->next&&outx->next->isc)//为首字母
			return com(root->next, outx->next, sw + root->dat, outx->end);
		else//判断是否为拼音
		{
			int j=1;
			for ( int k = outx->end; j < root->dat.length()&&outx; )
			{
				outx = outx->next;
				if (outx->dat == root->dat.substr(j, 1) && k + 1 == outx->beg)
				{
					j++;
					k = outx->end;
				}
				else
					break;
			}
			if (j == root->dat.length())
				return com(root->next, outx->next, sw + root->dat, outx->end);
			else
				return 0;
		}
	}
	else//当前outx所指的内容不是这一种敏感词分片，横向搜索
	{
		if (root->nei)
		{
			return com(root->nei, outx, sw, outx->end);
		}
		else
		{
			return 0;
		}
	}
}
void show(ofstream& ans)//将结果写入目标文档
{
	sto2 = store->next;
	while (sto2)
	{
		ans << "Line" << sto2->line << ": <" << sto2->sw1 << "> " << sto2->sw2 << endl;
		sto2 = sto2->next;
	}
}
int main(int argc, char** argv)
{
	char** x = argv;
	x++;
	ifstream words;
	words.open(*x);
	x++;
	ifstream org;
	org.open(*x);
	x++;
	ofstream ans;
	ans.open(*x);//打开文件
	string linestr;
	int total = 0, i = 1;//total记录总敏感词数
	mapping* root = NULL;//敏感词树的根节点
	rela* out;//映射链表头结点
	string a = "\0";
	//创建敏感词树
	while (!words.eof())
	{
		getline(words, linestr);
		root = cretree(linestr, 0, root, linestr.length());
	}
	while (!org.eof())
	{
		getline(org, linestr);
		out = trans(linestr);//转换储存到映射链表
		for (; out; out = out->next)//查找敏感词
		{
			if (com(root, out, a,out->end))
			{
				total++;
				sto3->line = i;
				sto3->sw2 = linestr.substr(out->beg, sto3->end - out->beg);
				sto2->next = sto3;
				sto2 = sto3;
			}
		}
		i++;
	}

	ans << "Total:" << total << endl;
	show(ans);

	words.close();
	org.close();
	ans.close();
	return 0;
}