#head file
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score , f1_score , recall_score , precision_score , classification_report
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC

# read path of a file
df = pd.read_csv("C:\\Users\\ayush\\OneDrive\\Documents\\credit_card_file.csv")

# count number of null in evey column
df.isnull().sum()

# countplot of class type 
df['Class'].value_counts()

# this data is unbalanced data 
legit = df[df['Class'] == 0]
fraud = df[df['Class'] == 1]

legit.shape
fraud.shape

legit.Amount.describe()


fraud.Amount.describe()            

legit = legit.sample(n = 492)
df_updated = pd.concat([legit , fraud] , axis = 0)
print(df_updated)

df_updated.shape
df_updated['Class'].value_counts()

x = df_updated.drop(columns= 'Class' , axis= 1)
y = df_updated['Class']

##Logistic Regression
x_train , x_test , y_train , y_test = train_test_split(x , y , test_size= 0.3 , random_state=42)

lg_model = LogisticRegression()
lg_model.fit(x_train , y_train)

# training on prediction
x_train_pred = lg_model.predict(x_train)

print("training data results : \n")

print("accuracy : " , accuracy_score(x_train_pred , y_train))
print("f1 score : " , f1_score(x_train_pred , y_train))
print("recall score : " , recall_score(x_train_pred , y_train))
print("precision_score : " , precision_score(x_train_pred , y_train))
print(classification_report(x_train_pred , y_train))

# training on test
print("\ntesting data results : ")
x_test_pred = lg_model.predict(x_test)
print("accuracy : " , accuracy_score(x_test_pred , y_test))
print("f1 score : " , f1_score(x_test_pred , y_test))
print("recall score : " , recall_score(x_test_pred , y_test))
print("precision_score : " , precision_score(x_test_pred , y_test))
print(classification_report(x_test_pred , y_test))

##Decision Tree Classifier
# Training data results
dt_model = DecisionTreeClassifier()
dt_model.fit(x_train, y_train)
print("Decision Tree - Training data results:\n")
x_train_pred = dt_model.predict(x_train)
print("Accuracy:", accuracy_score(x_train_pred, y_train))
print("F1 Score:", f1_score(x_train_pred, y_train))
print("Recall Score:", recall_score(x_train_pred, y_train))
print("Precision Score:", precision_score(x_train_pred, y_train))
print(classification_report(x_train_pred, y_train))

# Testing data results
print("\nDecision Tree - Testing data results:\n")
x_test_pred = dt_model.predict(x_test)
print("Accuracy:", accuracy_score(x_test_pred, y_test))
print("F1 Score:", f1_score(x_test_pred, y_test))
print("Recall Score:", recall_score(x_test_pred, y_test))
print("Precision Score:", precision_score(x_test_pred, y_test))
print(classification_report(x_test_pred, y_test))

# Random Forest Classifier

rf_model = RandomForestClassifier()
rf_model.fit(x_train, y_train)

# Training data results
print("Random Forest - Training data results:\n")
x_train_pred = rf_model.predict(x_train)
print("Accuracy:", accuracy_score(x_train_pred, y_train))
print("F1 Score:", f1_score(x_train_pred, y_train))
print("Recall Score:", recall_score(x_train_pred, y_train))
print("Precision Score:", precision_score(x_train_pred, y_train))
print(classification_report(x_train_pred, y_train))

# Testing data results
print("\nRandom Forest - Testing data results:\n")
x_test_pred = rf_model.predict(x_test)
print("Accuracy:", accuracy_score(x_test_pred, y_test))
print("F1 Score:", f1_score(x_test_pred, y_test))
print("Recall Score:", recall_score(x_test_pred, y_test))
print("Precision Score:", precision_score(x_test_pred, y_test))
print(classification_report(x_test_pred, y_test))


##SUPPORT VECTOR CLASSIFIER
# Training data results
svm_model = SVC()
svm_model.fit(x_train, y_train)
print("SVM - Training data results:\n")
x_train_pred = svm_model.predict(x_train)
print("Accuracy:", accuracy_score(x_train_pred, y_train))
print("F1 Score:", f1_score(x_train_pred, y_train))
print("Recall Score:", recall_score(x_train_pred, y_train))
print("Precision Score:", precision_score(x_train_pred, y_train))
print(classification_report(x_train_pred, y_train))

# Testing data results
print("\nSVM - Testing data results:\n")
x_test_pred = svm_model.predict(x_test)
print("Accuracy:", accuracy_score(x_test_pred, y_test))
print("F1 Score:", f1_score(x_test_pred, y_test))
print("Recall Score:", recall_score(x_test_pred, y_test))
print("Precision Score:", precision_score(x_test_pred, y_test))
print(classification_report(x_test_pred, y_test))