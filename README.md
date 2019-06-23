To use this project, download the BOOST library, unzip it and modify the path in the campus.pro file.

A campus is managed as follows: 

- If two campuses are in the same state and the same city then it's the same campus (equality)

- All teachers have an identification code
- If two teachers have an identical identification code but different from 0 then it's the same teacher (equality)

- There is 2 type of teacher: external and internal.
- A method can define the salary of a teacher.
- Wages of external teachers can be different.
- Wages are the same for interns.

- If two students have an id equal to 0 and they have the same name and same name then it's the same student (equality)
- If two students have an identical identification code but different from 0 then it's the same student (equality)

- When we want to consult the students list, we will have to sort them by their code

- If the number of students exceeds the campus capacity then we throw a FullCampusException error inherited from runtime_error

- The status of the campus will have to be saved under the JSON form.

- Methods for adding and removing teachers and students will have to be created.


