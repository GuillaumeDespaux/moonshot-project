# Project Charter

## Project Overview
The main goal of the project is to remove the task of call roll the morning and the afternoon for companies or schools, by doing it the the time cost of this task will be shut to 0 hours per weeks for the administration. 

## Scope
This project must be create a new ARDUINO hardware configurable only by the administration of the building, the users/students need to have a card to identify themselves to respond to the call roll when arriving, the system shouldn't need interaction from the administration except for the setup of the system.

### Constraints
- Users/students can exchange their cards to responds for someone else.
- Video identification is not allowed
- Finger printer is not allowed
To bypass those restrictions, the solution is to use a method to double authenticate the user/student, so create a software that confirm at 100% the presences of one specific user/student.

### Compatibility
There is a list on what devices have to be depending the platform:
1. Computers
- Windows
- MacOs
- UNIX
2. Phones
- Android
- iOS

## Stakeholders
| **Name/Group**  | **Role/Interest**                                    | **Contribution**                                          | **Communication Method**             |
|-----------------|------------------------------------------------------|-----------------------------------------------------------|--------------------------------------|
| Guillaume DESPAUX | Developer                                           | Responsible for the whole project execution and delivering the final product. | Meetings, Emails, Project Management Tools |
| Users           | Potential users of the final product                 | Represents the final target audience for the project.      | N/A (Final delivery and demo)        |

## Deliverables & Milestones
| **Milestone**             | **Document Name**           | **Deadlines** |
|---------------------------|-----------------------------|---------------|
| Functional Specification  | Functional Specification    | Not set       |
| Technical Specification   | Technical Specification     | Not set       |
| Hardware                  | None                        | Not set       |
| Software                  | src                         | Not set       |
| Test Plan                 | Test Plan                   | Not set       |
| User Manual               | User Manual                 | Not set       |

## Budget
For this project the cost in budget will be defined depending the resources will be:
1. Hardware
- ARDUINO Board = ?€
- NFC Reader = ?€
- Led = ?€
- Battery = ?€
- WI-FI Card = ?€
- NFC Card = ?€
2. Software
- API Server
- Code
- Database or Local Database ?

## Risks & Assumptions
| **ID** | **Description**                       | **Impact** | **Likelihood** | **Mitigation Strategy**                                      |
|--------|---------------------------------------|------------|----------------|--------------------------------------------------------------|
| 1      | Scope Adjustment                      | High       | Medium         | Establish clear requirements and approval process.           |
| 2      | Efficient Coordination                | Low        | Low            | Use project management tools and regular meetings to ensure alignment. |
| 4      | Full Attendance                       | Medium     | Medium         | Implement flexible working options and track attendance closely. |
| 6      | Defect Remediation                    | High       | Medium         | Prioritize testing and ensure a comprehensive test plan is in place. |
| 7      | Project Milestones                    | Medium     | Medium         | Regularly review progress, and adjust timelines as needed.    |
| 8      | Defect Remediation                    | High       | Medium         | Implement regular code reviews and testing to catch issues early. |
| 9      | Incompatible hardware pieces          | Critical   | Low            | Proper handling, secure storage when not in use, and have backup hardware available. |
| 11     | Unfamiliarity with some tools or languages | Medium | Medium         | Schedule training sessions and provide access to relevant tutorials. |
| 12     | Design Errors                         | High       | Medium         | Conduct regular design reviews and testing to catch errors early. |

