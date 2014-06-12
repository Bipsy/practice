module Fun.ADT where
	
	-- Government 
		-- String is name
	-- Company
		-- String is name
		-- Integer is ID number
		-- Person is Contact Person
		-- String is Contact Info of Person
	-- Individual
		-- Person is the person
		-- Bool is flag for further information
	data Client = 	Government 	String
				|	Company 	String Integer Person String
				| 	Individual	Person Bool
				deriving Show
	-- Person
		-- String is first name
		-- String is last name
	data Person	= 	Person String String Gender
				deriving Show
	data Gender = Male | Female | Unknown
				deriving Show

	clientName :: Client -> String
	clientName client = case client of
							Government name -> name
							Company name id person resp -> name
							Individual person info ->
								case person of Person fName lName gender -> fName ++ " " ++ lName
