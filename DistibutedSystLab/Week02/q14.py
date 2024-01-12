import pandas as pd

#define dictionary
student_data = {
	"Name": ["Akarsh", "Ishaan", "Sumit"],
	"Height": [178, 182, 173],
	"Qualification": ["B.Tech", "M.Sc.", "B.Arch"]
}

#convert dictionary to dataframe
students_df = pd.DataFrame(student_data)

print(students_df)

ages = [20, 24, 21]
#inserting ages at collumn 1
students_df.insert(1, "Age", ages)

print(students_df)
