;; Auto-generated. Do not edit!


(when (boundp 'tquad::LineSensor)
  (if (not (find-package "TQUAD"))
    (make-package "TQUAD"))
  (shadow 'LineSensor (find-package "TQUAD")))
(unless (find-package "TQUAD::LINESENSOR")
  (make-package "TQUAD::LINESENSOR"))

(in-package "ROS")
;;//! \htmlinclude LineSensor.msg.html


(defclass tquad::LineSensor
  :super ros::object
  :slots (_left _middle _right ))

(defmethod tquad::LineSensor
  (:init
   (&key
    ((:left __left) 0.0)
    ((:middle __middle) 0.0)
    ((:right __right) 0.0)
    )
   (send-super :init)
   (setq _left (float __left))
   (setq _middle (float __middle))
   (setq _right (float __right))
   self)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:middle
   (&optional __middle)
   (if __middle (setq _middle __middle)) _middle)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:serialization-length
   ()
   (+
    ;; float64 _left
    8
    ;; float64 _middle
    8
    ;; float64 _right
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _left
       (sys::poke _left (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _middle
       (sys::poke _middle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right
       (sys::poke _right (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _left
     (setq _left (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _middle
     (setq _middle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right
     (setq _right (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get tquad::LineSensor :md5sum-) "a9d7cdd3125cbdafd369bb29980024d5")
(setf (get tquad::LineSensor :datatype-) "tquad/LineSensor")
(setf (get tquad::LineSensor :definition-)
      "float64 left
float64 middle
float64 right
")



(provide :tquad/LineSensor "a9d7cdd3125cbdafd369bb29980024d5")


