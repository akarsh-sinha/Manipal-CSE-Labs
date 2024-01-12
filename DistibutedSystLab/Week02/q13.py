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

#creating address list
addresses = ["221B Baker St", "456 Ring Rd", "789 Park St"]

#adding addresses to dataframe
students_df["Address"] = addresses

print(students_df)
