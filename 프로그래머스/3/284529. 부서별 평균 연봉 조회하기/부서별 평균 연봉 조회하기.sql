select h.DEPT_ID, h.DEPT_NAME_EN, round(avg(e.SAL),0) as AVG_SAL
# select *
from HR_DEPARTMENT h inner join HR_EMPLOYEES e on h.DEPT_ID = e.DEPT_ID
group by h.DEPT_ID, h.DEPT_NAME_EN
order by AVG_SAL desc