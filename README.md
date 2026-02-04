# RISC-V-NPU
# Branch for DP1

AI Hardware Design League (AI-HDL) competition repository for integrating an NPU co-processor/extension onto a base RISC-V CPU.

# Competition rules
- we do not modify any of the RISC-V CPU verilog modules
- we DO modify the peripheral modules (peripheral.v)
- tt_wrapper.v (top module for connecting top module to cpu module)
- Leverage LLMs --> NO HUMAN CODE ALLOWED!
- Utilize prompt log and engineering. Do not just say 'hey design me an NPU', no, be thoughtful - this earns us major points. 

# Branch rules (4-tier)
1. Production   <- main
2. Test/QA      <- copy of main
3. Dev          <- development
4. Others       <- other branches (ours for features/tasks/anything else) ... based off dev

# Prior information from last year (I did my research...) 
youtube link: https://www.youtube.com/watch?v=qnI-e7D9PaI
LLM information (I put the link into notebook.lm):
* Overall Grand Prize Winner: The team "AI or die" won the best design overall, dominating both the undergraduate division and the general competition with high scores across all judged categories. They received a $5,000 cash prize.
* Career Advancement and Networking: The competition served as a gateway to the semiconductor industry, which speakers noted has become "cool again" and highly lucrative. Students sought to network with industry leaders from ARM, NVIDIA, and Texas Instruments to secure internships and full-time roles.

## Factors Leading to Victory
The teams that won succeeded by navigating a multi-phase design process and meeting rigorous technical criteria:
* Technical Optimization (PPA): Winners had to successfully optimize their hardware designs for Power, Performance, and Area (PPA). The overall winner, "AI or die," specifically stood out for maintaining a "fantastic design" that scored highly in every single one of these metrics.
* Hardware Security Integration: A critical factor for winning—and the focus of the final design phase—was the ability to incorporate security features at the design level. The "Most Secure Design" winner was chosen based on "very creative ways" to mitigate hardware vulnerabilities, which is more cost-effective than fixing issues after fabrication.
* Persistence and Bravery: Interestingly, the sources highlight that most participants had no prior experience with chip design. Success was attributed to students being "brave enough" to persist through the learning curve of world-class tools without a traditional background.
* Collaborative Design: Successful teams effectively managed the "design phases," which included setting up fundamentals, adding complex functionality, and finally performing deep optimization.
