select e.EMP_NO, e.EMP_NAME, (
    case
    when 96 <= avg(g.SCORE) then 'S'
    when 90 <= avg(g.SCORE) then 'A'
    when 80 <= avg(g.SCORE) then 'B'
    else 'C'
    end
) as GRADE, (
    case 
    when 96 <= avg(g.SCORE) then e.SAL * 0.2
    when 90 <= avg(g.SCORE) then e.SAL * 0.15
    when 80 <= avg(g.SCORE) then e.SAL * 0.1
    else 0
    end
) as BONUS
from HR_EMPLOYEES e join HR_GRADE g on e.EMP_NO = g.EMP_NO
group by e.EMP_NO, e.EMP_NAME
order by e.EMP_NO