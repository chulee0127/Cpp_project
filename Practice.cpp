#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int MID = 10;

class Lab {
private:
	int LabID;
	char * LabName;

public:
	Lab(int _LabID, const char * _LabName) {
		LabID = _LabID;
		LabName = new char[strlen(_LabName) + 1];
		strcpy(LabName, _LabName);
	}

	void LabShow() {
		cout << LabID << "    " << LabName << endl;
	}
};

class LabList {
private:
	Lab * LabArr[10];
	int index;
	int A;

public:
	LabList()
		:index(4), A(5) {}

	void addLabDefault() {
		LabArr[0] = new Lab(1, "�츮��");
		LabArr[1] = new Lab(2, "ABC��");
		LabArr[2] = new Lab(3, "�����ٷ�");
		LabArr[3] = new Lab(4, "���շ�");
	}

	void addLab() {
		char tname[50];

		cout << "===�� �߰�====" << endl;
		cout << "�� �̸�: ";
		cin >> tname;
		cout << "====================" << endl << endl;

		addLabQ4(A, tname);
		A++;
	}

	void addLabQ4(int _A, const char * tname) {
		LabArr[index++] = new Lab(_A, tname);
	}

	void LabShowAll() {
		cout << "-------------------------" << endl;
		cout << "ID      " << "����       " << endl;
		for (int i = 0; i < index; i++) {
			LabArr[i]->LabShow();
		}
		cout << "-------------------------" << endl;
	}
};

LabList Llist;

class Member {
private:
	int MID;
	int ID;
	char * name;

public:
	Member(int _MID, int _ID, const char * _name) {
		this->MID = _MID;
		ID = _ID;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	void MemberShow() {
		cout << MID << "        " << ID << "        " << name << endl;
	}

	~Member() {
		delete[]name;
	}
};

class Student : public Member {
public:
	Student(int _MID, int _ID, const char * _name)
		: Member(_MID, _ID, _name) {

	}

	void StudentShow() {
		MemberShow();
	}
};
class Professor : public Member {
public:
	Professor(int _MID, int _ID, const char * _name)
		: Member(_MID, _ID, _name) {

	}

	void ProfessorShow() {
		MemberShow();
	}
};

class MemberList {
private:
	Student * StudentArr[50];
	int A;
	int IDa;

	Professor * ProfessorArr[50];
	int B;
	int IDb;

public:
	MemberList()
		:A(4), B(5), IDa(5), IDb(6) {}

	void addStudentDefault() {
		StudentArr[0] = new Student(1, 1, "��ö��");
		StudentArr[1] = new Student(2, 2, "ȫ�浿");
		StudentArr[2] = new Student(3, 3, "�赿��");
		StudentArr[3] = new Student(4, 4, "��ö��");
	}

	void addStudent() {
		char tname[50];

		cout << "===�л� ���� �Է�====" << endl;
		cout << "�̸�: ";
		cin >> tname;
		cout << "====================" << endl << endl;

		addStudentQ2(MID, IDa, tname);
		IDa++;
	}

	void addStudentQ2(int _MID, int _IDa, const char * _tname) {
		StudentArr[A++] = new Student(_MID, _IDa, _tname);
		MID++;
	}

	void StudnetShowAll() {
		cout << " << �л� ��� >> " << endl;
		cout << "-------------------------" << endl;
		cout << "MID      " << "ID        " << "�̸�" << endl;
		for (int i = 0; i < A; i++) {
			StudentArr[i]->StudentShow();
		}
		cout << "-------------------------" << endl;
	}

	void addProfessorDefault() {
		ProfessorArr[0] = new Professor(5, 1, "�̿���");
		ProfessorArr[1] = new Professor(6, 2, "������");
		ProfessorArr[2] = new Professor(7, 3, "���ϵ�");
		ProfessorArr[3] = new Professor(8, 4, "������");
		ProfessorArr[4] = new Professor(9, 5, "���ο�");
	}

	void addProfessor() {
		char tname[50];

		cout << "===���� ���� �Է�====" << endl;
		cout << "�̸�: ";
		cin >> tname;
		cout << "====================" << endl << endl;

		addProfessorQ2(MID, IDb, tname);
		IDb++;
	}

	void addProfessorQ2(int _MID, int _IDb, const char * _tname) {
		ProfessorArr[B++] = new Professor(_MID, _IDb, _tname);
		MID++;
	}

	void ProfessorShowAll() {
		cout << " << ���� ��� >> " << endl;
		cout << "-------------------------" << endl;
		cout << "MID      " << "ID        " << "�̸�" << endl;
		for (int i = 0; i < B; i++) {
			ProfessorArr[i]->ProfessorShow();
		}
		cout << "-------------------------" << endl;
	}

	void MemberShowAll() {
		cout << " << ��� ��� >> " << endl;
		cout << "-------------------------" << endl;
		cout << "����      " << "MID      " << "ID        " << "�̸�" << endl;
		for (int i = 0; i < 4; i++) {
			cout << "�л�     ";
			StudentArr[i]->StudentShow();
		}
		for (int i = 0; i < 5; i++) {
			cout << "����     ";
			ProfessorArr[i]->ProfessorShow();
		}
		for (int i = 4; i < A; i++) {
			cout << "�л�     ";
			StudentArr[i]->StudentShow();
		}
		for (int i = 5; i < B; i++) {
			cout << "����     ";
			ProfessorArr[i]->ProfessorShow();
		}
		cout << "-------------------------" << endl;
	}

};

MemberList Mlist;

class MainMenu {
private:
	int choice;

public:
	int selectMenu() {

		cout << "1. �л� �߰�" << endl;
		cout << "2. ���� �߰�" << endl << endl;
		cout << "3. �л� ��� ��ȸ" << endl;
		cout << "4. ���� ��� ��ȸ" << endl;
		cout << "5. ��� ��� ��ȸ" << endl << endl;
		cout << "6. �� �߰�" << endl;
		cout << "8. �� ��� ���" << endl << endl;
		cout << "99. ȭ������" << endl;
		cout << "0. ����" << endl << endl;

		cout << " ���� >> ";
		cin >> choice;

		cout << endl;
		return choice;
	}
};

int main() {

	int a;
	MainMenu MM;

	Mlist.addStudentDefault();
	Mlist.addProfessorDefault();
	Llist.addLabDefault();

	while (true) {
		a = MM.selectMenu();

		if (a == 1) {
			Mlist.addStudent();
		}
		else if (a == 2) {
			Mlist.addProfessor();
		}
		else if (a == 3) {
			Mlist.StudnetShowAll();
		}
		else if (a == 4) {
			Mlist.ProfessorShowAll();
		}
		else if (a == 5) {
			Mlist.MemberShowAll();
		}
		else if (a == 6) {
			Llist.addLab();
		}
		else if (a == 8) {
			Llist.LabShowAll();
		}
		else if (a == 99) {
			system("cls");
		}
		else if (a == 0) {
			return 0;
		}
		else {
			cout << "��ȣ�� �ٽ� �����ϼ���" << endl << endl;
		}
	}
}