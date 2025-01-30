# Technical Specification Document

## 1. Project Overview

<div align="center">

**Project Name: None**<br>
**Project Manager:** [DESPAUX Guillaume](https://github.com/GuillaumeDespaux)<br>
**Last Update:** 01/29/2025<br>
**Version:** 0.1.0

</div>

## 2. Table of Contents

<details close>
<summary>Table of Contents</summary>

- [Technical Specification Document](#technical-specification-document)
  - [1. Project Overview](#1-project-overview)
  - [2. Table of Contents](#2-table-of-contents)
  - [3. Introduction](#3-introduction)
  - [4. Objectives](#4-objectives)
    - [4.1. Roll Call Taker](#41-roll-call-taker)
    - [4.2. Database](#42-database)
    - [4.3 API (Application Programming Interface)](#43-api-application-programming-interface)
    - [4.4. Software](#44-software)
  - [5. Project Folder Structure](#5-project-folder-structure)
  - [6. Convention](#6-convention)
    - [6.1. Naming Convention](#61-naming-convention)
    - [6.2. Code Convention](#62-code-convention)
      - [6.2.1. General](#621-general)
      - [6.2.2. Arduino](#622-arduino)
      - [6.2.3. API](#623-api)
      - [6.2.4. Software](#624-software)

</details>

## 3. Introduction

This project aims to develop a roll call taker solution linked to a database and a software. The roll call taker will be able to take roll calls of users and store them in a database. The software will be able for the users, to confirm their presence with an 2FA[^x] (Two Factor Authentication) system and for the administrator to manage the users presence or absence.

## 4. Objectives

The objectives of this project are:

### 4.1. Roll Call Taker

- Develop a roll call taker solution using Arduino[^y] language.
- Using a NFC[^z] reader to read the user's NFC card.
- Store the user's presence in a database.
- Connect the device to internet to send the data.

### 4.2. Database

- Develop a database structure to register companies, users and roll calls using Firebase[^a].
- Secure the database access for the users and the administrator.

### 4.3 API (Application Programming Interface)

- Develop an API[^b] to connected the Roll Call Taker to the database.
- Develop the routes to create a communication between the database and the administrators.

### 4.4. Software

- Develop a desktop software to manage the users presence using #TODO.
- Develop a 2FA system to confirm the user's presence.
- Identify the users with a device such as a smartphone or a computer (Mac Address[^c]) and the current internet connection.

## 5. Project Folder Structure

```bash #TODO
.
├── documents                      # Is for project documentation
│   ├── images                     # Is for storing images used in documentation
│   ├── management                 # Is for management documents
│   │   └── weekly_reports         # Is for weekly reports
│   ├── quality                    # Is for quality assurance documents
│   └── user_manual                # Is for user manuals
└── src                            # Is for source code
    ├── api                        # Is for API-related code
    │   ├── node_modules           # Is for Node.js modules
    │   ├── package-lock.json      # Is for npm package lock file
    │   ├── package.json           # Is for npm package configuration
    │   └── server.js              # Is for the API server code
    ├── app                        # Is for application code
    └── arduino                    # Is for Arduino code
```

## 6. Convention

This part is about the naming and code convention to follow during the development of the project.

### 6.1. Naming Convention

|**Type**|**Example**|**Convention Name**|
|---|---|---|
|Folder|`folder_name`|snake_case|
|File|`file_name`|snake_case|
|Variable|`bestVariable`|camelCase|
|Function|`best_Function`|camel_Snake_Case|
|Class|`className`|camelCase|
|Constant|`BestConstant`|PascalCase|
|Define|`BEST_DEFINE`|CONSTANT_CASE|
|Typedef|`TPDF_NAME`|CONSTANT_CASE|
|Structure|`s_Structure`|camel_Snake_Case|

>[!NOTE]
>
> - **Class :** Each class have to contain `class` in the name.
> - **Typedef :** Each typedef have to contain `TPDF` in the name.
> - **Structure :** Each structure have to contain `s_` in the name.

### 6.2. Code Convention

#### 6.2.1. General

```cpp
// Header file example .cpp
#include <iostream>
#include "library.hpp"

// Namespace
using namespace std;

// Constants
#define BEST_DEFINE 0

// Typedef
typedef int TPDF_NAME;

// Structure
struct s_Structure {
    int member;
};

// Class
class className {
    public:
        // Constructor
        className();
        // Destructor
        ~className();
        // Function
        void bestFunction();
    private:
        // Variable
        int bestVariable;
};

// Function

```

#### 6.2.2. Arduino

```ino
// Header file example .ino
```

```h
// Header file example .h
```

#### 6.2.3. API

```js
// Header file example .js
const bestConstant = require('bestConstant');

```

#### 6.2.4. Software

```unknown

```
