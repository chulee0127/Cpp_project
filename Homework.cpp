#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Lab { // ������ ��ü(������ ����Ʈ ���� �����Ѵ�)
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

Lab::~Lab() { // ��������� LabŬ������ �Ҹ��Ѵ�
	delete[]LabName;
}

class LabList { // ������ ��ü�� �̿��ϴ� Ŭ����(����Ʈ �� ����, ������ ���� ����, ������ ��ü ����, ������ ã��)
private:
	
	int index;

public:
	Lab * LabDefaultList[10]; // ������ ��ü 10������ ���� ����

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

LabList List; // LabList ��ü

void LabList::AddDefaultSubject() {

	AddLab(Lab(3, "��������"));
	AddLab(Lab(1, "��ü���⿬����"));
	AddLab(Lab(2, "Cpp������"));
	AddLab(Lab(4, "Java������"));

	SortAscending();
}

void LabList::SortAscending() { // ������ ����Ʈ�� ����
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

void LabList::AddLab(const Lab &s) { // ������ ��ü �߰��ϴ� �Լ�
	LabDefaultList[index++] = new Lab(s);
}

void LabList::FindSubject() {
	int id;

	while (true) {
		cout << "  >> ������ ID : ";
		cin >> id;

		if (id == 0)
			return;

		Lab *sp = FindSubject(id);

		if (sp == NULL) {
			cout << "  >> �׷� ID�� �����Ҵ� �����ϴ�..." << endl;
		}
		else {
			cout << "--------------------------------------" << endl;
			cout << "������ ID	  �����Ҹ�" << endl;
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
	cout << "������ ID	   �����Ҹ�" << endl;
	cout << "--------------------------------------" << endl;

	for (int i = 0; i < index; i++) {
		LabDefaultList[i]->LabListShow();
	}

	cout << "--------------------------------------" << endl;
}

LabList::~LabList() { // ���� ������ LabList Ŭ���� �Ҹ�
	for (int i = 0; i < index; i++)
		delete LabDefaultList[i];
}

class Person{ // �߰��� ��ü
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

class Student : public Person { // �߰��� �л� ��ü
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

class Professor : public Person { // �߰��� ���� ��ü
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

class PersonList: public LabList { // �л� ��ü�� 50������ �����ϴ� Ŭ����
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

void PersonList::AddStudent() { // �߰�

	int id;
	char tname[100];
	int subjId;

	cout << "<<�л������Է�>>" << endl;
	cout << "  - ID(���ڷ� �Է��ϼ���): ";
	cin >> id;
	cout << "  - �̸�: ";
	cin >> tname;

	cout << endl;

	List.LabListShowAll();
	cout << "  - ������ ID: ";
	cin >> subjId;

	Lab *subj = List.FindSubject(subjId);

	if (subj == NULL)
		cout << "  >> Student ��� ����.." << endl << endl;
	else {
		AddStudent(Student(id, tname, subj));

		cout << "  >> Student " << tname << " ��� ����.." << endl << endl;
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
	cout << "<<�л����>>" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "�л�ID	        �̸�	     ������ ID	       �����Ҹ�" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < A; i++)
		studentArr[i]->personShow();

	cout << "------------------------------------------------------------" << endl << endl;
}

void PersonList::AddProfessor() {

	int id;
	char tname[100];
	int subjId;

	cout << "<<���������Է�>>" << endl;

	cout << "  - ID(���ڷ� �Է��ϼ���): ";
	cin >> id;
	cout << "  - �̸�: ";
	cin >> tname;

	cout << endl;

	List.LabListShowAll();
	cout << "  - ������ ID: ";
	cin >> subjId;

	Lab *subj = List.FindSubject(subjId);

	if (subj == NULL)
		cout << "  >> Professor ��� ����.." << endl << endl;
	else {
		AddProfessor(Professor(id, tname, subj)); // �Լ��� �� ������ü ����

		cout << "  >> professor " << tname << " ��� ����.." << endl << endl;
	}
}

void PersonList::AddProfessor(const Professor &s) { // ���ο� ���� ��ü�� �����ϴ� �Լ�
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
	cout << "<<�������>>" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "����ID	        �̸�	     ������ ID	       �����Ҹ�" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < B; i++)
		professorArr[i]->ShowProfessor();

	cout << "------------------------------------------------------------" << endl << endl;
}

void PersonList::ShowAll() const {
	cout << "<<��ü ������ ���>>" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "����         ID	        �̸�	     ������ ID	       �����Ҹ�" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < A; i++) {
		cout << "�л�      ";
		studentArr[i]->ShowStudent();
	}

	for (int i = 0; i < B; i++) {
		cout << "����      ";
		professorArr[i]->ShowProfessor();
	}
	cout << "------------------------------------------------------------" << endl << endl;
}

void PersonList::ShowInfo() const {
	int z;
	cout << " << ������ ID �Է� >> " << endl;

	List.LabListShowAll();

	cout << "������ ID�� �Է��ϼ���: ";
	cin >> z;
	cout << "\n";

	cout << "<<������ ������ ���>>" << endl;
	cout << "---------------------------------" << endl;
	cout << "����         ID	        �̸�" << endl;
	cout << "---------------------------------" << endl;
	for (int i = 0; i < B; i++) { // �߰��� ��ü�� ���ϴ� �ݺ���
		for (int j = 0; j < 4; j++) { // �����ǰ��� ���ϴ� �ݺ���
			if (z == List.LabDefaultList[j]->GetId()) {
				cout << "����      ";
				professorArr[i]->ShowProfessorQ6();
				break;
			}
		}
	}
	
	for (int i = 0; i < A; i++) { // �߰��� ��ü�� ���ϴ� �ݺ���
		for (int j = 0; j < 4; j++) { // �����ǰ��� ���ϴ� �ݺ���
			if (z == List.LabDefaultList[j]->GetId()) {
				cout << "�л�      ";
				studentArr[i]->ShowStudentQ6();
				break;
			}
		}
	}
	cout << "---------------------------------" << endl;
}

PersonList::~PersonList() { // PersonList �Ҹ�
	for (int i = 0; i < A; i++) // �л���ü �Ҹ�
		delete studentArr[i];

	for (int i = 0; i < B; i++) // ������ü �Ҹ�
		delete professorArr[i];
}

class MainMenu { // �޴� Ŭ����
public:
	int selectMenu() {

		int sel; // �޴���ȣ �Է¹��� ����

		cout << "------ �� �� ------" << endl;
		cout << "  1. �л� �߰�" << endl;
		cout << "  2. ���� �߰�" << endl << endl;
		cout << "  3. �л���� ���" << endl;
		cout << "  4. ������� ���" << endl << endl;
		cout << "  5. ��ü ������ ���" << endl;
		cout << "  6. �����Һ� ������ ���" << endl << endl;
		cout << "  0. ����" << endl;
		cout << "-------------------" << endl;

		cout << "  ����>> ";
		cin >> sel;

		cout << endl;
		return sel; // main������ a��
	}
};

int main() {

	MainMenu mm;
	List.AddDefaultSubject(); // ������ ����Ʈ�� ����

	int a; // �Է¹��� �޴���ȣ

	while (true) {
		a = mm.selectMenu(); // MainMenuŬ������ ���� �޴���ȣ�� �Է¹޴´�

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
			cout << "  >> �����մϴ�..." << endl;

			return 0;
		}
		else {
			cout << "  >> �޴���ȣ�� �ٽ� �Է��ϼ��� " << a << endl;
		}
	}

}