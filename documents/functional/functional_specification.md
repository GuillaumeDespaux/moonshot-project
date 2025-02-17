# Functional Specification Document

## Project Overview

<div align="center">

**Project Name: None**<br>
**Project Manager:** [DESPAUX Guillaume](https://github.com/GuillaumeDespaux)<br>
**Last Update:** 01/23/2025<br>
**Version:** 0.2.0

</div>

## Table of Contents

<details close>
<summary>Click to expand</summary>

- [Functional Specification Document](#functional-specification-document)
  - [Project Overview](#project-overview)
  - [Table of Contents](#table-of-contents)
  - [1. Introduction](#1-introduction)
  - [2. Objectives](#2-objectives)
  - [3. Scope](#3-scope)
    - [3.1. For Companies/Organizations](#31-for-companiesorganizations)
    - [3.2. For Users](#32-for-users)
  - [4. Out of Scope Features](#4-out-of-scope-features)
    - [4.1. For Companies/Organizations](#41-for-companiesorganizations)
    - [4.2. For Users](#42-for-users)
    - [4.3. General](#43-general)
  - [5. Functional Requirements](#5-functional-requirements)
    - [5.1 Hardware](#51-hardware)
    - [5.2 API](#52-api)
    - [5.3 Database](#53-database)
    - [5.4 Software (2FA)](#54-software-2fa)
    - [5.5 Global Interaction Overview](#55-global-interaction-overview)
  - [6. Non-Functional Requirements](#6-non-functional-requirements)
    - [6.1 Performance](#61-performance)
    - [6.2 Security](#62-security)
    - [6.3 Usability](#63-usability)
  - [7. Use Cases](#7-use-cases)
    - [7.1. Use Case 1: User Identification](#71-use-case-1-user-identification)
    - [7.2. Use Case 2: User Verification](#72-use-case-2-user-verification)
  - [8. Assumptions and Constraints](#8-assumptions-and-constraints)
  - [9. Glossary](#9-glossary)
  - [10. Appendices](#10-appendices)

</details>

## 1. Introduction

Some years ago when I where trainer with my parents, doing roll call was a simple and straightforward task. We had approximately 10 trainees per session, so there where no difficulty at all for this task. However when I stopped being a trainer, and became myself a trainee again, I understood that doing this task, depends on the size of the organization. For instance when I arrived in 2023 at ALGOSUP's school and saw Jean-Philipe losing around 20 to 30 minutes each morning and afternoon doing the roll call. This observation have been making me thinking: "Why don't we automate this task?".

## 2. Objectives

This is why today I present this project as moon shot. The main goal is to stop losing time doing this, and for companies who don't want lose energy. The main purpose is to create something easy to use, compatible with a lot of computers, and also make it the less expensive as possible.

## 3. Scope

The project will consist of two main products: a hardware component for user identification and an application for user verification. The goals for those products are to simplify the life of each companies that have daily registration with many people.

### 3.1. For Companies/Organizations

- **Ease to use**: Designed to be intuitive and straightforward, minimizing the need for training or specialized skills.
- **Quick access to results**: Provides fast and reliable attendance reports to streamline decision-making and operations.
- **Automation of roll call**: Eliminates the need for manual attendance-taking, saving time and reducing errors.
- **Time saving**: Frees up valuable time for employees to focus on higher priority tasks.

### 3.2. For Users

- **Ease to use**: Simple interface to ensure smooth user interaction without confusion.
- **Improved discipline**: Encourages punctuality and accountability through reliable tracking systems.
- **Enhanced productivity**: Allows users to focus on their work rather than attendance-related tasks, contributing to overall efficiency.
- **Compatibility**: The users will be able to use the software for any computers (Windows, macOs, Linux).

## 4. Out of Scope Features

### 4.1. For Companies/Organizations

- **Automatically assigning blame**: The system will not determine or assign fault to individuals, as this exceeds the intended purpose of simplifying roll calls and introduces ethical and technical challenges.
- **Integration with disciplinary systems**: Features for managing disciplinary actions, such as issuing warnings or escalating absences, are not included.

### 4.2. For Users

- **Predicting lateness**: The system will not forecast lateness using external factors (e.g., traffic or weather) due to the complexity and additional resources required for such functionality.
- **Preventing absences**: The system’s role is limited to recording attendance, not actively preventing absences or enforcing user behavior.
- **Productivity tools**: Features like reminders or personal notifications to improve time management.
- **Phones**: The system's compatibility will be only on computers discarding the phones option at least for the prototype.

### 4.3. General

- **Unrelated functionalities**: Any features not directly related to automating roll calls or tracking attendance will not be addressed in this project.

## 5. Functional Requirements

The functional requirements define the specific features and capabilities of the system, including hardware, software, and data interactions.

### 5.1 Hardware

- **Internet Connectivity**: The hardware must be connected to the Internet to communicate with the API[^2].
- **Local Data Storage**: The hardware should store data locally in case of Internet connectivity issues.
- **Data Transmission**: The hardware must send data online at least twice a day to ensure information readability.
- **User Identification Creation**: The system should allow the creation of new user identification cards.
- **User Identification Reading**: The system must read user identification cards to retrieve information.
- **User Identification Updating**: The system should provide an update mechanism for users who leave the organization.
- **User Identification Deletion**: The system must be able to delete user identification card information.

<div align="center">

```mermaid
graph
    subgraph Hardware Interaction
    start((User))-- Use Card --> hardware[/Hardware/]
    end
```

</div>

### 5.2 API

- **Information Reception from Hardware**: The API[^2] must receive information from the hardware for analysis.
- **Information Sorting**: The API[^2] should efficiently sort all received information.
- **Information Transmission**: The API[^2] must send information to the application to confirm the second step of authentication.

<div align="center">

```mermaid
graph
    subgraph API Interaction
    api[/API/]
    hardware{Hardware} --Card Information--> api
    end
```

</div>

### 5.3 Database

- **Store Information**: The database[^6] must securely store all user and attendance information, ensuring data integrity and availability.
- **Give Information**: The database[^6] should provide quick and reliable access to stored information for authorized users and systems.
- **Keep Information A Certain Amount Of Time**: The database[^6] must retain information for a specified duration, complying with organizational policies and legal requirements.

<div align="center">

```mermaid
graph
    subgraph Database Interaction
    db[(Database)]
    api[/API/] --ID Exist?--> db
    db --Yes/No --> apipro
    apipro{API}
    end
```

</div>

### 5.4 Software (2FA)

- **Role Differentiation**: Users will have different options based on their roles within the organization.
- **Background Operation**: The application should run in the background, displaying pop-ups based on user roles.
- **Unique User Identification**: The application must obtain the computer's MAC Address[^4] to ensure the person activating the hardware is the same person validating through the application.

<div align="center">

```mermaid
graph
    subgraph Software Interaction
    app{Software}
    apipro{API} --Notification--> app
    app --Ask--> user
    user[/User/] --Confirm--> appreq[/Software/]
    appreq --Mac Address--> api
    end
```

</div>

### 5.5 Global Interaction Overview

<div align="center">

```mermaid
graph
subgraph Global Interaction
    stop(((Stop)))
    subgraph Hardware Interaction
    start((User))-- Use Card --> hardware[/Hardware/]
    end

    subgraph API Interaction
    api[/API/]
    hardware{Hardware} --Card Information--> api
    end

    subgraph Database Interaction
    db[(Database)]
    api[/API/] --ID Exist?--> db
    db --Yes--> apipro
    db --No --> stop
    apipro{API}
    end

    subgraph Software Interaction
    app{Software}
    apipro{API} --Notification--> app
    app --Ask--> user
    user[/User/] --Confirm--> appreq[/Software/]
    user[/User/] --Don't Confirm--> stop
    appreq --Mac Address--> api
    end
end
```

</div>

## 6. Non-Functional Requirements

The non-functional requirements define the quality attributes of the system, such as performance, security, and usability.

### 6.1 Performance

- **Battery Life**: The hardware should have a long-lasting battery to ensure continuous operation throughout the day without frequent recharging between 14 days and 31 days.
- **Duration**: The system must be capable of handling high volumes of data and user interactions without degradation in performance over extended periods to prevent users be needed to buy often new device.
- **Response Time**: The system should provide quick response times for all operations, including user identification, data transmission, and report generation in less than 2 seconds, to ensure a seamless user experience.

### 6.2 Security

- **GDP Compliance**: The system must comply with GDPR[^3] regulations to protect user data and ensure privacy.
- **Account Security**: User accounts should be protected with strong authentication mechanisms to prevent unauthorized access.
- **Role-Based Access Control**: The system should implement role-based access control to ensure that users can only access information and perform actions that are relevant to their roles.

### 6.3 Usability

- **Compatibility with Computers**: The system should be compatible with various operating systems, including Windows, macOS, and Linux, to ensure broad usability.
- **Exclusion of Phones**: The system is designed to be used on computers only, and will not support mobile phone compatibility.
- **Authentication System**: The system should include a robust authentication system to verify user identities and ensure secure access to the application and data.

## 7. Use Cases

### 7.1. Use Case 1: User Identification

|Photo|Name|Age|Job|Description|
|---|---|---|---|---|
|![John Doe](https://via.placeholder.com/150)|John Doe|35|Software Engineer|John is a dedicated software engineer working at a mid-sized tech company. He is responsible for developing and maintaining various software applications. John values efficiency and is always looking for ways to streamline his workflow. He has basic computer skills and is comfortable using new software tools with minimal training.|
|![Jane Smith](https://via.placeholder.com/150)|Jane Smith|22|Student|Jane is a diligent student currently enrolled in a computer science program at a university. She is responsible for attending lectures, completing assignments, and participating in group projects. Jane is tech-savvy and comfortable using various software applications. She values punctuality and strives to maintain a good attendance record.|

### 7.2. Use Case 2: User Verification

|Photo|Name|Age|Job|Description|
|---|---|---|---|---|
|![Alice Johnson](https://via.placeholder.com/150)|Alice Johnson|45|Human Resources Manager|Alice is the Human Resources Manager at a large corporation. She is responsible for overseeing employee relations, recruitment, and compliance with labor laws. Alice values efficiency and is always looking for ways to improve HR processes. She has advanced computer skills and is comfortable using various software tools to manage HR tasks.|
|![Emily Clark](https://via.placeholder.com/150)|Emily Clark|40|School Principal|Emily is the Principal of a large high school. She is responsible for overseeing the daily operations of the school, managing staff, and ensuring a safe and productive learning environment. Emily values efficiency and is always looking for ways to improve administrative processes. She has low computer skills and is uncomfortable using various software tools to manage school operations.|

## 8. Assumptions and Constraints

- **Assumptions**:
  - The system will be used in a professional environment with a stable Internet connection.
  - Users will have basic computer skills and be able to operate the system with minimal training.
  - The system will be used primarily for attendance tracking and not for other purposes.
- **Constraints**:
  - The system will not support mobile devices or tablets, focusing exclusively on desktop and laptop computers.
  - The system will not include advanced technology such as facial recognition or biometric authentication due to environmental where the system will be used.

## 9. Glossary

[^1] :**2FA (Two-Factor Authentication):** A security process in which the user provides two different authentication factors to verify themselves.

[^2] :**API (Application Programming Interface):** A set of rules and definitions that allows software programs to communicate with each other.

[^3] :**GDPR (General Data Protection Regulation):** A regulation in EU law on data protection and privacy for all individuals within the European Union and the European Economic Area.

[^4] :**MAC Address (Media Access Control Address):** A unique identifier assigned to network interfaces for communications on the physical network segment.

[^5] :**Hardware:** The physical components of a computer system.

[^6] :**Database:** An organized collection of data, generally stored and accessed electronically from a computer system.

[^7] :**Local Data Storage:** The storage of data on a local device rather than on a remote server.


## 10. Appendices
<!-- Include any additional information or documents that support the functional specification. -->