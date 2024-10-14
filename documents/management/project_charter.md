# Project Charter

## Project Overview
The main goal of the project is to eliminate the task of roll call in the morning and afternoon for companies or schools. By doing so, the time cost of this task will be reduced to 0 hours per week for the administration.

## Scope
This project must create a new ARDUINO hardware, configurable only by the administration of the building. The users/students will need a card to identify themselves for roll call when arriving. The system should not require interaction from the administration, except for the initial setup.

### Constraints
- Users/students can exchange their cards to respond for someone else.
- Video identification is not allowed.
- Fingerprint identification is not allowed.

To bypass these restrictions, the solution is to use a method for double authentication of the user/student. This will create a software that confirms 100% the presence of a specific user/student.

### Compatibility
Here is a list of devices that must be supported depending on the platform:
1. Computers
    - Windows
    - macOS
    - UNIX
2. Phones
    - Android
    - iOS

## Stakeholders
| **Name/Group**   | **Role/Interest**                                  | **Contribution**                                          | **Communication Method**             |
|------------------|----------------------------------------------------|-----------------------------------------------------------|--------------------------------------|
| Guillaume DESPAUX | Developer                                          | Responsible for the overall project execution and delivery of the final product. | Meetings, Emails, Project Management Tools |
| Users            | Potential users of the final product               | Represents the final target audience for the project.      | N/A (Final delivery and demo)        |

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
For this project, the budget will be defined based on the following resources:
1. Hardware
    - ARDUINO Board = ?€
    - NFC Reader = ?€
    - LED = ?€
    - Battery = ?€
    - WI-FI Card = ?€
    - NFC Card = ?€
2. Software
    - API Server
    - Code
    - ~~Database or Local Database?~~
3. Time
    - 

## Risks & Assumptions
| **ID** | **Description**                       | **Impact** | **Likelihood** | **Mitigation Strategy**                                      |
|--------|---------------------------------------|------------|----------------|--------------------------------------------------------------|
| 1      | Scope Adjustment                      | High       | Medium         | Establish clear requirements and an approval process.         |
| 2      | Efficient Coordination                | Low        | Low            | Use project management tools and regular meetings to ensure alignment. |
| 4      | Full Attendance                       | Medium     | Medium         | Implement flexible working options and track attendance closely. |
| 6      | Defect Remediation                    | High       | Medium         | Prioritize testing and ensure a comprehensive test plan is in place. |
| 7      | Project Milestones                    | Medium     | Medium         | Regularly review progress and adjust timelines as needed.     |
| 8      | Defect Remediation                    | High       | Medium         | Implement regular code reviews and testing to catch issues early. |
| 9      | Incompatible hardware pieces          | Critical   | Low            | Proper handling, secure storage when not in use, and have backup hardware available. |
| 11     | Unfamiliarity with some tools or languages | Medium  | Medium         | Schedule training sessions and provide access to relevant tutorials. |
| 12     | Design Errors                         | High       | Medium         | Conduct regular design reviews and testing to catch errors early. |
