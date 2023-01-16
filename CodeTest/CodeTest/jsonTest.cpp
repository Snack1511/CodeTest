#include<iostream>
#include <fstream>
#include<tuple>
#include "json.hpp"
#include "json_fwd.hpp"
using namespace std;
using json = nlohmann::json;
typedef tuple<int, string, string, int, int, int, int, int, int, int, int, int, int, int, int, int> TupleData;
enum class Tag {
	ID, NAME, AKA, LEVEL, CLAN, ATT, MENTAL, PHYSICAL, WISDOM, GOLD, SKILL, CHARM, RING, DICE, SKIN, TAUNT
	,TagEnd
};
void SaveJson(json* pJsonData, const char* szPath)
{
	ofstream fout(szPath);
	fout << (*pJsonData);
	fout.close();

}
void LoadJson(json* pJsonData, const char* szPath)
{
	ifstream fin(szPath);
	fin >> (*pJsonData);
	fin.close();
}

void SetJson(json* pJsonData, TupleData DataTuple)
{

	(*pJsonData).push_back(get<int(Tag::ID)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::NAME)> (DataTuple).c_str());
	(*pJsonData).push_back(get<int(Tag::AKA)> (DataTuple).c_str());
	(*pJsonData).push_back(get<int(Tag::LEVEL)> (DataTuple));
	(*pJsonData).push_back(get<int(Tag::CLAN)>(DataTuple));

	//ATT, MENTAL, PHYSICAL, WISDOM, GOLD, SKILL,
	(*pJsonData).push_back(get<int(Tag::ATT)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::MENTAL)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::PHYSICAL)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::WISDOM)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::GOLD)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::SKILL)>(DataTuple));

	//CHARM, RING, DICE, SKIN, TAUNT
	(*pJsonData).push_back(get<int(Tag::CHARM)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::RING)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::DICE)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::SKIN)>(DataTuple));
	(*pJsonData).push_back(get<int(Tag::TAUNT)>(DataTuple));
}
void PrintJson(vector<string> TagName, json jsonData)
{
	for (int i = 0; i < Tag::TagEnd; ++i)
	{
		cout << TagName[i].c_str() << " : " << jsonData[i] << endl;
	}
}
int main() 
{
	TupleData DataTuple, DataTuple2, DataTuple3;
	DataTuple = make_tuple(0, string("Dan"), string("Winter Wolf"), 0, 0, 5, 5, 3, 3, 4, 0, 0, 0, 0, 0, 0);
	DataTuple2 = make_tuple(1, string("Dan2"), string("Winter Wolf2"), 0, 0,4, 6, 5, 3, 4, 0, 0, 0, 0, 0, 0);
	DataTuple3 = make_tuple(2, string("Dan3"), string("Winter Wolf3"), 0, 0, 3, 4, 3, 3, 4, 0, 0, 0, 0, 0, 0);
	vector<string> TagName;
	TagName.push_back("HeroID");
	TagName.push_back("HeroName");
	TagName.push_back("HeroAKA");
	TagName.push_back("MasterLevel");
	TagName.push_back("ClanType");
	TagName.push_back("Attack");
	TagName.push_back("Physical");
	TagName.push_back("Mental");
	TagName.push_back("Wisdom");
	TagName.push_back("Gold");
	TagName.push_back("SkillID");
	TagName.push_back("Charm");
	TagName.push_back("Ring");
	TagName.push_back("Dice");
	TagName.push_back("Skin");
	TagName.push_back("Taunt");
	
	//json JData;
	//string TagString = "Hello";
	//string TagString2 = "int";
	//string DataString = "World";
	//JData.emplace(TagString.c_str(), DataString.c_str());
	//JData.emplace(TagString2.c_str(), 0);
	//SaveJson(&JData, "test.json");
	//cout << JData[TagString.c_str()] << endl;
	//cout << JData["int"] << endl;


	//json JInData;
	//LoadJson(&JInData, "test.json");
	//cout << JInData[TagString.c_str()] << endl;
	//cout << JInData[TagString2.c_str()] << endl;

	json JData[3];
	json JInData[3];
	//JData.emplace(TagName[Tag::ID].c_str(), get<Tag::ID>(DataTuple));
	//JData.emplace(TagName[Tag::NAME].c_str(), get<Tag::NAME>(DataTuple).c_str());
	//JData.emplace(TagName[Tag::AKA].c_str(), get<Tag::AKA>(DataTuple).c_str());
	//JData.emplace(TagName[Tag::LEVEL].c_str(), get<Tag::LEVEL>(DataTuple));
	//JData.emplace(TagName[Tag::CLAN].c_str(), get<Tag::CLAN>(DataTuple));

	////ATT, MENTAL, PHYSICAL, WISDOM, GOLD, SKILL,
	//JData.emplace(TagName[Tag::ATT].c_str(), get<Tag::ATT>(DataTuple));
	//JData.emplace(TagName[Tag::MENTAL].c_str(), get<Tag::MENTAL>(DataTuple));
	//JData.emplace(TagName[Tag::PHYSICAL].c_str(), get<Tag::PHYSICAL>(DataTuple));
	//JData.emplace(TagName[Tag::WISDOM].c_str(), get<Tag::WISDOM>(DataTuple));
	//JData.emplace(TagName[Tag::GOLD].c_str(), get<Tag::GOLD>(DataTuple));
	//JData.emplace(TagName[Tag::SKILL].c_str(), get<Tag::SKILL>(DataTuple));

	////CHARM, RING, DICE, SKIN, TAUNT
	//JData.emplace(TagName[Tag::CHARM].c_str(), get<Tag::CHARM>(DataTuple));
	//JData.emplace(TagName[Tag::RING].c_str(), get<Tag::RING>(DataTuple));
	//JData.emplace(TagName[Tag::DICE].c_str(), get<Tag::DICE>(DataTuple));
	//JData.emplace(TagName[Tag::SKIN].c_str(), get<Tag::SKIN>(DataTuple));
	//JData.emplace(TagName[Tag::TAUNT].c_str(), get<Tag::TAUNT>(DataTuple));
	//SetJson(&JData[0], DataTuple);
	//SetJson(&JData[1], DataTuple2);
	//SetJson(&JData[2], DataTuple3);

	//for (int i = 0; i < 3; ++i)
	//{
	//	cout << "================================" << "[" << i << "]" << "========================================= " << endl;
	//	PrintJson(TagName, JData[i]);

	//}

	//json SaveData;
	//for (int i = 0; i < 3; ++i) 
	//{
	//	SaveData.push_back(JData[i]);
	//}
	//SaveJson(&SaveData, "test.json");
	cout << "================================ Load =========================================" << endl;
	json LoadData;
	LoadJson(&LoadData, "test.json");
	for (int i = 0; i < 3; ++i)
	{
		JInData[i] = LoadData[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		cout << "================================" << "[" << i << "]" << "========================================= " << endl;
		PrintJson(TagName, JInData[i]);
	}

	return 0;
}