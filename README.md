# Enhancing Passenger Trust Toward Cooperative Autonomous Vehicles Using Simulated AR Displays

This repository contains the code, simulation assets, experiment files, and analysis supporting the paper:

**Paper:**  
“Enhancing Passenger Trust Toward Cooperative Autonomous Vehicles Using Simulated Augmented Reality Displays”  
*AutomotiveUI ’25 — Brisbane, Australia*



<table>
  <tr>
    <td align="center">
      <img src="figures/int1Edited.gif" width="250"><br>
      <strong>Concept A</strong>
    </td>
    <td align="center">
      <img src="figures/int2Edited.gif" width="250"><br>
      <strong>Concept B</strong>
    </td>
    <td align="center">
      <img src="figures/int3Edited.gif" width="250"><br>
      <strong>Concept C</strong>
    </td>
  </tr>
</table>

## Authors
- Hady Ahmed Mohamed Farahat  
- Malak Sadek  
- Sherif Aly  
- Khalil Elkhodary  
- Amr Elmougy  

**Affiliations:**  
American University in Cairo | Imperial College London | University of Cambridge

---

## Overview

Future Fully Autonomous Vehicles (FAVs) will operate not only independently but also in cooperative multi-agent environments, using V2X technology to negotiate road conditions, lane changes, and shared traffic maneuvers.

A major barrier to adoption is **passenger trust**—not only in their own vehicle (ego) but also in cooperating vehicles around them.

This project investigates how **Augmented Reality (AR) interfaces** can improve trust, situational awareness, and user acceptance of cooperative autonomous vehicles.


## Tools and Technologies

This project uses the following tools and technologies: **Python, C++, C, and Jupyter Notebook**.

---

## Research Goal

Investigate how three different AR transparency concepts impact:

- Trust in the ego vehicle  
- Trust in nearby cooperating AVs  
- Situational awareness  
- Cognitive workload  
- Technology acceptance  

The study simulates cooperative driving scenarios using virtual reality, custom AR overlays, and V2X-based information sharing.

---

## System Architecture

This project integrates:

- **DReyeVR simulator** (Unreal Engine)  
- Custom **path-planning algorithms**  
- **V2V/V2I communication modules**  
- **AR interface rendering** inside VR  
- **Scenario scripts** for cooperative maneuvers  
- **Data collection and statistical analysis**

---

## Interface Concepts

Three AR interface concepts were implemented:

**A — No Transparency**  
- Shows only vehicle speed  
- No information about ego intentions or other agents  

**B — System-Level Transparency**  
- Shows the ego vehicle’s planned path  
- Helps predict ego behavior but no insight into surrounding vehicles  

**C — Environment-Level Transparency (V2X-enabled)**  
- Shows cooperative intentions  
- Shows other vehicles’ planned paths  
- Shows road blockages and infrastructure  
- Includes a mini-map with full situational information  
- Most advanced and effective concept  

---

## Driving Scenario

A 3-minute VR scenario includes:

- Tunnel road blockage  
- Emergency vehicle swerve  
- Cooperative lane-change negotiation  
- Vehicles cutting in  
- Sharp turns and unexpected maneuvers  

All interfaces use the same scenario in a **counterbalanced Latin Square order**.

---

## User Study

- **Participants:** 30 (ages 18–34, M = 23.8)  
- **Measurements:**  
  - Trust in Automation  
  - SART (Situational Awareness)  
  - NASA-TLX (Cognitive Load)  
  - TAM (Technology Acceptance Model)  

## Key Results

| Metric                     | Interface A                | Interface B                 | Interface C                 |
|---------------------------|----------------------------|-----------------------------|-----------------------------|
| **Trust (Ego Vehicle)**              | 2.10 ± 0.93                | 4.18 ± 1.12                 | 5.44 ± 1.14                 |
| **Trust (Cooperative Vehicles)**    | 2.07 ± 1.06                | 2.98 ± 1.20                 | 4.88 ± 1.31                 |
| **Situational Awareness (SART)**    | 1.82 ± 0.89                | 4.21 ± 1.07                 | 5.60 ± 1.00                 |
| **Cognitive Workload (NASA‑TLX)**   | 2.55 ± 0.74                | 2.35 ± 0.94                 | 2.95 ± 1.34                 |
| **Technology Acceptance (TAM)**     | see paper / analysis data  | see paper / analysis data   | see paper / analysis data   |


## Repository Structure

- **src/** — AR overlays, V2X logic, DReyeVR modifications  
- **simulation/** — Maps, scenarios, configuration files  
- **analysis/** — Statistical notebooks  
- **data/** — (Optional) raw and processed study data  
- **docs/** — Paper and documentation  
- **figures/** — Screenshots and graphs  


---

## How to Run

1. Install dependencies from `requirements.txt`  
2. Install **Unreal Engine** and **DReyeVR**  
3. Run the cooperative scenario  
4. Analyze results using notebooks in `/analysis`  

---

## License

MIT License (modifiable)

---

## Citation

Farahat, H.A.M., Sadek, M., Aly, S., Elkhodary, K., & Elmougy, A. (2025).  
*Enhancing Passenger Trust Toward Cooperative Autonomous Vehicles Using Simulated Augmented Reality Displays.*  
AutomotiveUI ’25, Brisbane, Australia.
