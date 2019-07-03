#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Lab { // 연구소 객체(연구소 디폴트 값을 저장한다)
private:
	int id;
	char * LabName;

public:
	Lab(int _id, const char * _LabName);
	Lab(const Lab &s);

	int GetId() const {
		return id;
	};
	char *GetTitle() const {
		return LabName;
	};

	void LabListShow() const;
	~Lab();
};

Lab::Lab(int _id, const char * _LabName) {
	id = _id;
	LabName = new char[strlen(_LabName) + 1];
	strcpy(LabName, _LabName);
}

Lab::Lab(const Lab &s) {
	id = s.id;
	LabName = new char[strlen(s.LabName) + 1];
	strcpy(LabName, s.LabName);
}

void Lab::LabListShow() const {
	cout << "    " << id << "          " << LabName << endl;
}

Lab::~Lab() { // 복사생성한 Lab클래스를 소멸한다
	delete[]LabName;
}

class LabList { // 연구소 객체를 이용하는 클래스(디폴트 값 지정, 연구소 목차 정렬, 연구소 전체 나열, 연구소 찾기)
private:
	
	int index;

public:
	Lab * LabDefaultList[10]; // 연구소 객체 10개까지 생성 가능

	LabList()
		: index(0) {

	}
	void AddDefaultSubject();
	void SortAscending();
	void AddLab(const Lab &s);
	void FindSubject();

	Lab * FindSubject(int id) const;

	void LabListShowAll() const;
	~LabList();
};

LabList List; // LabList 객체

void LabList::AddDefaultSubject() {

	AddLab(Lab(3, "웹연구소"));
	AddLab(Lab(1, "객체지향연구소"));
	AddLab(Lab(2, "Cpp연구소"));
	AddLab(Lab(4, "Java연구소"));

	SortAscending();
}

void LabList::SortAscending() { // 연구소 디폴트값 정렬
	for (int i = 0; i < index; i++) {
		for (int j = i + 1; j < index; j++) {
			if (LabDefaultList[i]->GetId() > LabDefaultList[j]->GetId()) {
				Lab *t = LabDefaultList[i];
				LabDefaultList[i] = LabDefaultList[j];
				LabDefaultList[j] = t;
			}
		}
	}
}

void LabList::AddLab(const Lab &s) { // 연구소 객체 추가하는 함수
	LabDefaultList[index++] = new Lab(s);
}

void LabList::FindSubject() {
	int id;

	while (true) {
		cout << "  >> 연구소 ID : ";
		cin >> id;

		if (id == 0)
			return;

		Lab *sp = FindSubject(id);

		if (sp == NULL) {
			cout << "  >> 그런 ID의 연구소는 없습니다..." << endl;
		}
		else {
			cout << "--------------------------------------" << endl;
			cout << "연구소 ID	  연구소명" << endl;
			cout << "--------------------------------------" << endl;

			sp->LabListShow();
			cout << "--------------------------------------" << endl;
		}
	}
}

Lab *LabList::FindSubject(int id) const {
	for (int i = 0; i < index; i++) {
		if (LabDefaultList[i]->GetId() == id)
			return LabDefaultList[i];
	}

	return NULL;
}

void LabList::LabListShowAll() const {
	cout << "--------------------------------------" << endl;
	cout << "연구소 ID	   연구소명" << endl;
	cout << "--------------------------------------" << endl;

	for (int i = 0; i < index; i++) {
		LabDefaultList[i]->LabListShow();
	}

	cout << "--------------------------------------" << endl;
}

LabList::~LabList() { // 복사 생성한 LabList 클래스 소멸
	for (int i = 0; i < index; i++)
		delete LabDefaultList[i];
}

class Person{ // 추가할 객체
private:
	int id;
	char * name;
	Lab *subj;

public:
	Person(int _id, char *_name, Lab *_subj);
	Person(const Person &_s);

	int GetId() {
		return id;
	};
	char * GetName() {
		return name;
	}
	Lab * Getsubj() {
		return subj;
	}

	void personShow() const;
	void personShowQ6() const;
	~Person();
};

Person::Person(int _id, char *_name, Lab *_subj) {
	id = _id;
	name = new char[strlen(_name) + 1];

	strcpy(name, _name);
	subj = _subj;
}

Person::Person(const Person &s) {
	id = s.id;
	name = new char[strlen(s.name) + 1];

	strcpy(name, s.name);
	subj = s.subj;
}

void Person::personShow() const {
	cout << " " << id << "      	" << name << "	         " << subj->GetId() << "       	" << subj->GetTitle() << endl;
}

void Person::personShowQ6() const {
	cout << " " << id << "      	" << name << endl;
}

Person::~Person() {
	delete[]name;
}

class Student : public Person { // 추가할 학생 객체
public:
	Student(int _id, char *_name, Lab *_subj)
		:Person(_id, _name, _subj) {

	}

	void ShowStudent() const;
	void ShowStudentQ6() const;
};

void Student::ShowStudent() const {
	personShow();
}

void Student::ShowStudentQ6() const {
	personShowQ6();
}

class Professor : public Person { // 추가할 교수 객체
public:
	Professor(int _id, char *_name, Lab *_subj)
		:Person(_id, _name, _subj) {

	}

	void ShowProfessor() const;
	void ShowProfessorQ6() const;
};

void Professor::ShowProfessor() const {
	personShow();
}

void Professor::ShowProfessorQ6() const {
	personShowQ6();
}

class PersonList: public LabList { // 학생 객체를 50개까지 관리하는 클래스
private:
	Student * studentArr[50];
	int A;

	Professor * professorArr[50];
	int B;

public:
	PersonList()
		: A(0), B(0) {

	}

	void AddStudent();
	void AddStudent(const Student &s);

	Person *FindStudent(char *name);

	void ShowStudent() const;

	void AddProfessor();
	void AddProfessor(const Professor &s);

	Professor *FindProfessor(char *name);

	void ShowProfessor() const;

	void ShowAll() const;
	void ShowInfo() const;

	~PersonList();
};

PersonList personList;

void PersonList::AddStudent() { // 추가

	int id;
	char tname[100];
	int subjId;

	cout << "<<학생정보입력>>" << endl;
	cout << "  - ID(숫자로 입력하세요): ";
	cin >> id;
	cout << "  - 이름: ";
	cin >> tname;

	cout << endl;

	List.LabListShowAll();
	cout << "  - 연구소 ID: ";
	cin >> subjId;

	Lab *subj = List.FindSubject(subjId);

	if (subj == NULL)
		cout << "  >> Student 등록 실패.." << endl << endl;
	else {
		AddStudent(Student(id, tname, subj));

		cout << "  >> Student " << tname << " 등록 성공.." << endl << endl;
	}
}

void PersonList::AddStudent(const Student &s) {
	studentArr[A++] = new Student(s);
}

Person *PersonList::FindStudent(char *name) {
	for (int i = 0; i < A; i++) {
		if (strcmp(studentArr[i]->GetName(), name) == 0)
			return studentArr[i];
	}

	return NULL;
}

void PersonList::ShowStudent() const {
	cout << "<<학생목록>>" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "학생ID	        이름	     연구소 ID	       연구소명" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < A; i++)
		studentArr[i]->personShow();

	cout << "------------------------------------------------------------" << endl << endl;
}

void PersonList::AddProfessor() {

	int id;
	char tname[100];
	int subjId;

	cout << "<<교수정보입력>>" << endl;

	cout << "  - ID(숫자로 입력하세요): ";
	cin >> id;
	cout << "  - 이름: ";
	cin >> tname;

	cout << endl;

	List.LabListShowAll();
	cout << "  - 연구소 ID: ";
	cin >> subjId;

	Lab *subj = List.FindSubject(subjId);

	if (subj == NULL)
		cout << "  >> Professor 등록 실패.." << endl << endl;
	else {
		AddProfessor(Professor(id, tname, subj)); // 함수로 들어가 교수객체 생성

		cout << "  >> professor " << tname << " 등록 성공.." << endl << endl;
	}
}

void PersonList::AddProfessor(const Professor &s) { // 새로운 교수 객체를 생성하는 함수
	professorArr[B++] = new Professor(s);
}

Professor *PersonList::FindProfessor(char *name) {
	for (int i = 0; i < B; i++) {
		if (strcmp(professorArr[i]->GetName(), name) == 0)
			return professorArr[i];
	}

	return NULL;
}

void PersonList::ShowProfessor() const {
	cout << "<<교수목록>>" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "교수ID	        이름	     연구소 ID	       연구소명" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < B; i++)
		professorArr[i]->ShowProfessor();

	cout << "------------------------------------------------------------" << endl << endl;
}

void PersonList::ShowAll() const {
	cout << "<<전체 구성원 목록>>" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "구분         ID	        이름	     연구소 ID	       연구소명" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < A; i++) {
		cout << "학생      ";
		studentArr[i]->ShowStudent();
	}

	for (int i = 0; i < B; i++) {
		cout << "교수      ";
		professorArr[i]->ShowProfessor();
	}
	cout << "------------------------------------------------------------" << endl << endl;
}

void PersonList::ShowInfo() const {
	int z;
	cout << " << 연구소 ID 입력 >> " << endl;

	List.LabListShowAll();

	cout << "연구소 ID를 입력하세요: ";
	cin >> z;
	cout << "\n";

	cout << "<<연구실 구성원 목록>>" << endl;
	cout << "---------------------------------" << endl;
	cout << "구분         ID	        이름" << endl;
	cout << "---------------------------------" << endl;
	for (int i = 0; i < B; i++) { // 추가된 객체를 비교하는 반복문
		for (int j = 0; j < 4; j++) { // 연구실값을 비교하는 반복문
			if (z == List.LabDefaultList[j]->GetId()) {
				cout << "교수      ";
				professorArr[i]->ShowProfessorQ6();
				break;
			}
		}
	}
	
	for (int i = 0; i < A; i++) { // 추가된 객체를 비교하는 반복문
		for (int j = 0; j < 4; j++) { // 연구실값을 비교하는 반복문
			if (z == List.LabDefaultList[j]->GetId()) {
				cout << "학생      ";
				studentArr[i]->ShowStudentQ6();
				break;
			}
		}
	}
	cout << "---------------------------------" << endl;
}

PersonList::~PersonList() { // PersonList 소멸
	for (int i = 0; i < A; i++) // 학생객체 소멸
		delete studentArr[i];

	for (int i = 0; i < B; i++) // 교수객체 소멸
		delete professorArr[i];
}

class MainMenu { // 메뉴 클래스
public:
	int selectMenu() {

		int sel; // 메뉴번호 입력받을 변수

		cout << "------ 메 뉴 ------" << endl;
		cout << "  1. 학생 추가" << endl;
		cout << "  2. 교수 추가" << endl << endl;
		cout << "  3. 학생목록 출력" << endl;
		cout << "  4. 교수목록 출력" << endl << endl;
		cout << "  5. 전체 구성원 출력" << endl;
		cout << "  6. 연구소별 구성원 출력" << endl << endl;
		cout << "  0. 종료" << endl;
		cout << "-------------------" << endl;

		cout << "  선택>> ";
		cin >> sel;

		cout << endl;
		return sel; // main문에서 a값
	}
};

int main() {

	MainMenu mm;
	List.AddDefaultSubject(); // 연구소 디폴트값 설정

	int a; // 입력받을 메뉴번호

	while (true) {
		a = mm.selectMenu(); // MainMenu클래스에 들어가서 메뉴번호를 입력받는다

		if (a == 1) {
			personList.AddStudent();
		}
		else if (a == 2) {
			personList.AddProfessor();
		}
		else if (a == 3) {
			personList.ShowStudent();
		}
		else if (a == 4) {
			personList.ShowProfessor();
		}
		else if (a == 5) {
			personList.ShowAll();
		}
		else if (a == 6) {
			personList.ShowInfo();
		}
		else if (a == 0) {
			cout << "  >> 종료합니다..." << endl;

			return 0;
		}
		else {
			cout << "  >> 메뉴번호를 다시 입력하세요 " << a << endl;
		}
	}

}