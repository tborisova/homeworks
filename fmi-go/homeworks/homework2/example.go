package main

import (
	"encoding/json"
	"fmt"
	"strconv"
)

type Susi struct {
	Students    map[int]*Student
	Courses     map[string]*Course
	Enrollments map[string]*Enrollment
}

type SusiError struct {
	Student *Student
	Course  *Course
	Message string
}

type Course struct {
	CourseName          string `json:"course_name"`
	CourseIdentifier    string `json:"course_identifier"`
	MinimumAcademicYear int    `json:"minimum_academic_year"`
	MastersOnly         bool   `json:"masters_only"`
	AvailablePlaces     int    `json:"available_places"`
}

type Student struct {
	FacultyNumber int    `json:"faculty_number"`
	FirstName     string `json:"first_name"`
	LastName      string `json:"last_name"`
	AcademicYear  int    `json:"academic_year"`
	Master        bool   `json:"master"`
}

type Enrollment struct {
	Course  *Course
	Student *Student
}

func (course *Course) String() string {
	return fmt.Sprint("%s %s", course.CourseIdentifier, course.CourseName)
}

func (student *Student) String() string {
	return strconv.Itoa(student.FacultyNumber) + " " + student.FullName()
}

func (e *SusiError) Error() string {
	return e.Message
}

func NewSusi() *Susi {
	susi := new(Susi)
	susi.Students = make(map[int]*Student)
	susi.Courses = make(map[string]*Course)
	susi.Enrollments = make(map[string]*Enrollment)
	return susi
}

func (susi *Susi) AddStudent(request []byte) error {

	student := new(Student)

	if err := json.Unmarshal(request, &student); err != nil {
		return err
	}

	if _, err := susi.FindStudent(student.FacultyNumber); err == nil {
		return &SusiError{Course: nil, Message: fmt.Sprintf("Студент с факултетен номер %d вече съществува!", student.FacultyNumber), Student: student}
	}

	susi.Students[student.FacultyNumber] = student
	return nil
}

func (susi *Susi) AddCourse(request []byte) error {

	course := new(Course)
	if err := json.Unmarshal(request, &course); err != nil {
		return err
	}

	if st, _ := susi.FindCourse(course.CourseIdentifier); st != nil {
		return &SusiError{Course: st, Message: fmt.Sprintf("Курс с identifier %s вече съществува!", course.CourseIdentifier), Student: nil}
	}

	susi.Courses[course.CourseIdentifier] = course

	return nil
}

func (s *Susi) Enroll(request []byte) error {
	type Enroll struct {
		FacultyNumber    int    `json:"faculty_number"`
		CourseIdentifier string `json:"course_identifier"`
	}

	enroll := new(Enroll)
	err := json.Unmarshal(request, &enroll)
	if err != nil {
		return err
	}

	student, err := s.FindStudent(enroll.FacultyNumber)
	if err != nil {
		return err
	}

	course, err := s.FindCourse(enroll.CourseIdentifier)
	if err != nil {
		return err
	}

	enrollment, _ := s.FindEnrollment(enroll.FacultyNumber, enroll.CourseIdentifier)

	if enrollment != nil {
		return &SusiError{Message: fmt.Sprintf("Студент с факултетен номер %d вече е записан за курс с identifier %s!", enroll.FacultyNumber, enroll.CourseIdentifier), Student: student, Course: course}
	}

	if course.AvailablePlaces == 0 {
		return &SusiError{Message: fmt.Sprintf("Няма свободни места за курс с identifier - %s!", enroll.CourseIdentifier), Student: student, Course: course}
	}

	if (!student.Master && course.MastersOnly) || student.AcademicYear < course.MinimumAcademicYear {
		return &SusiError{Course: course, Student: student, Message: fmt.Sprintf("%s не покрива изискванията за %s!", student.FullName(), course.CourseName)}
	} else {
		course.AvailablePlaces -= 1
		s.Enrollments[strconv.Itoa(enroll.FacultyNumber)+"_"+enroll.CourseIdentifier] = &Enrollment{Course: course, Student: student}
		return nil
	}
}

func (s *Susi) FindEnrollment(facultyNumber int, courseIdentifier string) (*Enrollment, error) {

	student, err := s.FindStudent(facultyNumber)

	if err != nil {
		return nil, err
	}

	course, err := s.FindCourse(courseIdentifier)

	if err != nil {
		return nil, err
	}

	enrollment, ok := s.Enrollments[strconv.Itoa(facultyNumber)+"_"+courseIdentifier]

	if ok {
		return enrollment, nil
	} else {
		return nil, &SusiError{Course: course, Student: student, Message: fmt.Sprintf("Студент с факултетен номер %d не е записан за курса с identifier %s!", facultyNumber, courseIdentifier)}
	}

}

func (s *Susi) FindStudent(facultyNumber int) (*Student, error) {

	student, ok := s.Students[facultyNumber]
	if ok {
		return student, nil
	} else {
		return nil, &SusiError{Student: nil, Message: fmt.Sprintf("Няма студент с факултетен номер %d!", facultyNumber), Course: nil}
	}
}

func (s *Susi) FindCourse(courseIdentifier string) (*Course, error) {

	course, ok := s.Courses[courseIdentifier]

	if ok {
		return course, nil
	} else {
		return nil, &SusiError{Course: nil, Message: "Няма курс с identifier - " + courseIdentifier + "!", Student: nil}
	}
}

func (s *Student) FullName() string {
	return s.FirstName + " " + s.LastName
}
