# Project Charter

## Project Overview
The main goal of the project is to eliminate the task of roll call in the morning and afternoon for companies or schools. By doing so, the time cost of this task will be reduced to 0 hours per week for the administration.

## Scope
This project must create a new hardware, only configurable by the administration of the building. The users will be needed to use a card to identify themselves when arriving. Then once identified, they will be asked to validate on their computer a demand to confirm their arrival (2FA). The system should not require interaction from the administration, except for the initial setup and the consultation of documents.

### Constraints
- Users can exchange their cards to respond for someone else.
- Video identification is not allowed.
- Fingerprint identification is not allowed.
- Users can use their personal devices rather the one given by one organization.

To bypass these restrictions, the solution is to use a method with double authentication from the user. This will conduct to create a software that confirms 100% the user's presence.

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
| **Milestone**             | **Document Name**           |
|---------------------------|-----------------------------|
| Functional Specification  | Functional Specification    |
| Technical Specification   | Technical Specification     |
| Hardware                  | arduino                     |
| Software                  | src                         |
| Test Plan                 | Test Plan                   |
| User Manual               | User Manual                 |

## Budget
For this project, the budget will be defined based on the following resources:
1. Hardware
    - ESP32 = ?€
    - NFC Reader = ?€
    - LED = ?€
    - Battery = ?€
    - WI-FI Card = ?€
    - NFC Card = ?€
    - Screen = ?€
2. Software
    - API Server
    - Code
    - Database Server

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
