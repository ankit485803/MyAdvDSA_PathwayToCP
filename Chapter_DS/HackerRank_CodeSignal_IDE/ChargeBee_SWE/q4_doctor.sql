


SELECT DISTINCT d1.name, d1.specialty, d1.hospital
FROM doctors d1
JOIN doctors d2 
ON d1.hospital = d2.hospital 
AND d1.specialty <> d2.specialty
ORDER BY d1.specialty DESC;
