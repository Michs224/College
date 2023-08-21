CREATE DATABASE MangaShop
DROP TABLE IF EXISTS MsCustomer
DROP TABLE IF EXISTS TransactionDetail
DROP TABLE IF EXISTS MsManga
DROP TABLE IF EXISTS MsGenre
DROP TABLE IF EXISTS MsStaff
DROP TABLE IF EXISTS TransactionHeader
DROP TABLE IF EXISTS MsRole

USE MangaShop

CREATE TABLE [MsCustomer] (
	CustomerID CHAR(5) PRIMARY KEY CHECK(CustomerID LIKE 'CS[0-9][0-9][0-9]'),
	CustomerName VARCHAR(50) NOT NULL,
	CustomerPhone VARCHAR(15) NOT NULL,
	CustomerAddress VARCHAR(50) NOT NULL,
)

CREATE TABLE [MsGenre] (
 GenreID CHAR(5) PRIMARY KEY CHECK (GenreID LIKE 'GE[0-9][0-9][0-9]'),
 GenreManga VARCHAR(15) NOT NULL

)

CREATE TABLE [MsManga] (
	MangaID CHAR(5) PRIMARY KEY CHECK (MangaID LIKE 'MG[0-9][0-9][0-9]'),
	MangaTitle VARCHAR(20) NOT NULL,
	GenreID CHAR(5) CHECK (GenreID LIKE 'GE[0-9][0-9][0-9]'),
	MangaPrice INT NOT NULL,
	MangaAuthor VARCHAR(30) NOT NULL,
	MangaRating FLOAT NOT NULL,
	MangaChapter INT NOT NULL,
	CONSTRAINT FK_Genre FOREIGN KEY (GenreID) REFERENCES MsGenre(GenreID)
)

INSERT INTO MsCustomer VALUES 
('CS001', 'Dirk Titterell', '01234567', '74 Melvin Point'),
('CS002', 'Dukey Diano', '09875666', '92 Sugar Alley'),
('CS003', 'Alex Meekins', '5473944', '577 Dovetail Park'),
('CS004', 'Cherice Jermey', '27382372', '811 Debs Street'),
('CS005', 'Ingamar Carlin', '839816423', '389 Surrey Pass'),
('CS006', 'Pooh McCutcheon', '0372163871', '7 Melby Trail'),
('CS007', 'Silvain Jozsa', '193724348', '19269 Maryland Hill'),
('CS008', 'Javier Drewson', '198391738', '8 Moulton Point'),
('CS009', 'Wilbur Francino', '10964155', '21840 Golden Leaf Avenue'),
('CS010', 'Sadie Snow', '1536142', '70 Eagle Crest Hill')

DROP TABLE IF EXISTS MsStaff
SELECT * FROM MsCustomer

CREATE TABLE [MsRole](
	RoleID CHAR(5) PRIMARY KEY CHECK(RoleID LIKE 'RL[0-9][0-9][0-9]'),
	RoleName VARCHAR(20) NOT NULL
)

CREATE TABLE [MsStaff] (
	StaffID CHAR(5) PRIMARY KEY CHECK(StaffID LIKE 'ST[0-9][0-9][0-9]'),
	StaffName VARCHAR(50) NOT NULL,
	StaffPhone VARCHAR(15) NOT NULL,
	StaffAddress VARCHAR(100) NOT NULL,
	Sales INT NOT NULL,
	AtStore VARCHAR(30) NOT NULL,
	RoleID CHAR(5) NOT NULL,
	Salary INT NOT NULL,
	HiredDate DATE NOT NULL,
	CONSTRAINT FK_Role FOREIGN KEY (RoleID) REFERENCES MsRole(RoleID)
)


CREATE TABLE MsPaymentType (
	PaymentID CHAR(5) PRIMARY KEY CHECK(PaymentID LIKE 'PT[0-9][0-9][0-9]'),
	PaymentMethod CHAR(5) NOT NULL

)

CREATE TABLE [MsStore] (
	StoreID CHAR(5) PRIMARY KEY CHECK(StoreID LIKE 'SE[0-9][0-9][0-9]'),
	StoreName VARCHAR(30) NOT NULL,
	StoreAddress VARCHAR(100) NOT NULL
)

CREATE TABLE [TransactionHeader] (
	TransactionID CHAR(5) PRIMARY KEY CHECK(TransactionID LIKE 'TR[0-9][0-9][0-9]'),
	TransactionDate DATE NOT NULL,
	StoreID CHAR(5) NOT NULL,
	StaffID CHAR(5) NOT NULL,
	PaymentID CHAR(5) NOT NULL,
	CustomerID CHAR(5) NOT NULL,

	CONSTRAINT FK_Store FOREIGN KEY (StoreID) REFERENCES MsStore(StoreID),
	CONSTRAINT FK_Staff FOREIGN KEY (StaffID) REFERENCES MsStaff(StaffID),
	CONSTRAINT FK_Payment FOREIGN KEY (PaymentID) REFERENCES MsPaymentType(PaymentID),
	CONSTRAINT FK_Customer FOREIGN KEY (CustomerID) REFERENCES MsCustomer(CustomerID)
	)

	DROP TABLE IF EXISTS TransactionDetail

CREATE TABLE [TransactionDetail] (
	TransactionID CHAR(5) PRIMARY KEY CHECK(TransactionID LIKE 'TR[0-9][0-9][0-9]'),
	MangaID CHAR(5) NOT NULL,
	Quantity INT NOT NULL

	CONSTRAINT FK_Transaction FOREIGN KEY (TransactionID) REFERENCES TransactionHeader(TransactionID),
	CONSTRAINT FK_Manga FOREIGN KEY (MangaID) REFERENCES MsManga(MangaID)

	)

	INSERT INTO MsGenre VALUES
	('GE003','Fantasy'),
	('GE002','Adventure'),
	('GE001','Action')

	INSERT INTO MsManga VALUES
	('MG001','One Piece','GE003',50000,'Michael Geraldin W',4.9,1065),
	('MG002','Hunter X Hunter','GE002',60000,'Zaky Satya Gumilang',3.5,335),
	('MG003','Boruto','GE001',100000,'Heru Deliansyah',2.8,550)


	INSERT INTO MsRole VALUES
	('RL001','CEO'),
	('RL002','Staff'),
	('RL003','Manager')

	--DELETE FROM MsStaff
	--WHERE StaffName='Steceint Nar3'

	INSERT INTO MsStaff VALUES
		('ST002','Steceint Nar2','0192918213','SQL Street2',5,'MangaShop2','RL002',10000000,'2004-03-24'),
		('ST001','Steceint Nar','0718278213','SQL Street',5,'MangaShop','RL001',60000000,'1995-02-28'),
		('ST003','Steceint Nar3','0718278215','SQL Streetl',5,'MangaShop','RL003',60000000,'1995-05-28')
		


	SELECT MangaTitle [Title],MangaAuthor [author],MangaPrice [Price]
	FROM MsManga
	WHERE MangaRating >3.3

	SELECT * FROM MsManga
	WHERE MangaChapter>(
	SELECT AVG(MangaChapter)
	FROM MsManga
	)

	--UPDATE MsStaff
	--SET Salary=Salary * 1.1
	--WHERE MONTH(HiredDate)=3;

	SELECT * FROM MsStaff

BEGIN TRAN
ALTER TABLE MsStaff
ALTER COLUMN StaffPhone VARCHAR(13) NOT NULL
ROLLBACK

SELECT td.TransactionID,Quantity,MangaTitle,MangaAuthor
FROM TransactionHeader th
JOIN TransactionDetail td ON td.TransactionID=th.TransactionID
JOIN MsManga mm ON mm.MangaID=td.MangaID
WHERE MangaAuthor LIKE '%i'

SELECT MC.CustomerID,CustomerName,COUNT(th.TransactionID) [Total Transaction],mm.MangaID
FROM TransactionHeader th
JOIN MsCustomer MC ON MC.CustomerID=th.CustomerID
JOIN TransactionDetail td ON td.TransactionID=th.TransactionID
JOIN MsManga mm ON mm.MangaID = td.MangaID
WHERE MONTH(TransactionDate)>6 AND LEN(CustomerName)<16
GROUP BY MC.CustomerID,CustomerName,mm.MangaID



SELECT TOP 10 StaffName,TransactionID,CustomerName
FROM TransactionHeader th
JOIN MsCustomer MC ON MC.CustomerID=th.CustomerID
JOIN MsStaff ms ON ms.StaffID=th.StaffID
WHERE SUBSTRING(MC.CustomerID, PATINDEX('%[0-9]%', MC.CustomerID), LEN(MC.CustomerID)) % 2 = 1
ORDER BY ms.Salary DESC

--ATAU GINI
SELECT TOP 10 StaffName,TransactionID,CustomerName
FROM TransactionHeader th
JOIN MsCustomer MC ON MC.CustomerID=th.CustomerID
JOIN MsStaff ms ON ms.StaffID=th.StaffID
WHERE RIGHT(MC.CustomerID,1)='1'
	OR RIGHT(MC.CustomerID,1)='3'
	OR RIGHT(MC.CustomerID,1)='5'
	OR RIGHT(MC.CustomerID,1)='7'
	OR RIGHT(MC.CustomerID,1)='9'
ORDER BY ms.Salary DESC

SELECT Total,MM.MangaID,MM.MangaTitle,MM.MangaPrice FROM
(SELECT TOP 10 mm.MangaID,COUNT(mm.MangaID) [Total], MangaTitle,MangaPrice
FROM TransactionHeader th
JOIN TransactionDetail td ON td.TransactionID=th.TransactionID
JOIN MsManga mm ON mm.MangaID=td.MangaID
GROUP BY mm.MangaID,MangaTitle,MangaPrice
ORDER BY Total DESC
) AS MangaTop
JOIN MsManga MM ON MangaTop.MangaID=MM.MangaID


SELECT th.TransactionID [ID],StaffName,mr.RoleID,HiredDate,StoreAddress 
FROM TransactionHeader th
JOIN TransactionDetail td ON td.TransactionID=th.TransactionID
JOIN MsStaff ms ON ms.StaffID=th.StaffID
JOIN MsStore mstore ON mstore.StoreID=th.StoreID
JOIN MsRole mr ON mr.RoleID=ms.RoleID
WHERE MONTH(HiredDate)>2 AND RoleName='Manager' AND AtStore LIKE '%l%' AND CAST(RIGHT(StaffPhone,2) AS INT ) % 2 =1


SELECT CustomerID, CustomerName
FROM MsCustomer
WHERE CustomerID IN (
  SELECT CustomerID
  FROM TransactionHeader
  WHERE StaffID IN (
    SELECT StaffID
    FROM MsStaff
    WHERE CAST(SUBSTRING(StaffID, LEN(StaffID), 1) AS INT) % 2 = 0
  )
  GROUP BY CustomerID
  HAVING COUNT(*) < 2
)