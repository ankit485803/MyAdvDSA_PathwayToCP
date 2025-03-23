


WITH MaxOrder AS (
    SELECT ordered_by, MAX(price) AS max_price
    FROM orders
    GROUP BY ordered_by
)
SELECT c.first_name || ' ' || c.last_name AS full_name, m.max_price
FROM MaxOrder m
JOIN customers c ON m.ordered_by = c.customer_id
ORDER BY m.max_price DESC, full_name ASC;



-- another method

SELECT 
    CONCAT(c.first_name, ' ', c.last_name) AS customer_name,
    o.price AS max_order_price
FROM 
    customers c
JOIN 
    orders o
ON 
    c.customer_id = o.ordered_by
JOIN 
    (SELECT ordered_by, MAX(price) AS max_price FROM orders GROUP BY ordered_by) m
ON 
    o.ordered_by = m.ordered_by AND o.price = m.max_price
ORDER BY 
    max_order_price DESC, customer_name ASC;
